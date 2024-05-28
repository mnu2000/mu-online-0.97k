﻿using System;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace kayito_Editor.Source
{
	public class CItem
	{
		public const int ITEM_SIZE = 10;

		public bool IsEmpty = true;

		public byte Slot = 0xFF;

		public uint Serial = 0;

		public int Section = 0xFF;

		public int Index = 0xFF;

		public int ItemLevel = 0;

		public int ItemDurability = 255;

		public int SkillOption = 0;

		public int LuckOption = 0;

		public int AdditionalOption = 0;

		public int ExcellentOption = 0;

		public Image ItemImage = Properties.Resources.unknownItem;

		private byte[] ItemHex = new byte[ITEM_SIZE] { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

		public CItem()
		{

		}

		public void Clear()
		{
			this.IsEmpty = true;

			this.Slot = 0xFF;

			this.Serial = 0;

			this.Section = 0xFF;

			this.Index = 0xFF;

			this.ItemLevel = 0;

			this.ItemDurability = 255;

			this.SkillOption = 0;

			this.LuckOption = 0;

			this.AdditionalOption = 0;

			this.ExcellentOption = 0;

			this.ItemImage = Properties.Resources.unknownItem;

			this.ItemHex = new byte[ITEM_SIZE] { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
		}

		public void Convert(byte[] lpMsg)
		{
			if (lpMsg[0] == 0xFF && (lpMsg[7] & 0x80) == 0x80 && (lpMsg[9] & 0xF0) == 0xF0)
			{
				this.IsEmpty = true;

				return;
			}

			int ItemIndex = lpMsg[0] | ((lpMsg[9] & 0xF0) * 32) | ((lpMsg[7] & 0x80) * 2);

			this.Section = ItemIndex / 32;

			this.Index = ItemIndex % 32;

			this.ItemLevel = (lpMsg[1] / 8) & 15;

			this.ItemDurability = lpMsg[2];

			this.SkillOption = (lpMsg[1] / 128) & 1;

			this.LuckOption = (lpMsg[1] / 4) & 1;

			this.AdditionalOption = (lpMsg[1] & 3) + ((lpMsg[7] & 64) / 16);

			this.Serial = BitConverter.ToUInt32(lpMsg, 3);

			this.ExcellentOption = lpMsg[7] & 63;

			string image = String.Format(".\\Data\\Items\\{0}\\{1}.jpg", this.Section, this.Index);

			if (File.Exists(image))
			{
				this.ItemImage = Image.FromFile(image);
			}

			this.IsEmpty = false;
		}

		public void Convert(int section, int index, int level, int dur, int skill, int luck, int add, int exe)
		{
			this.Section = section;

			this.Index = index;

			this.ItemLevel = level;

			this.ItemDurability = dur;

			this.SkillOption = skill;

			this.LuckOption = luck;

			this.AdditionalOption = add;

			this.Serial = 0;

			this.ExcellentOption = exe;

			string image = String.Format(".\\Data\\Items\\{0}\\{1}.jpg", this.Section, this.Index);

			if (File.Exists(image))
			{
				this.ItemImage = Image.FromFile(image);
			}

			this.IsEmpty = false;
		}

		public byte[] GetItemHex()
		{
			if (this.IsEmpty == true)
			{
				return this.ItemHex;
			}

			this.ItemHex[0] = (byte)((this.Section * ItemManager.MAX_ITEM_TYPE + this.Index) & 0xFF);

			this.ItemHex[1] = 0;
			this.ItemHex[1] |= (byte)(this.ItemLevel * 8);
			this.ItemHex[1] |= (byte)(this.SkillOption * 128);
			this.ItemHex[1] |= (byte)(this.LuckOption * 4);
			this.ItemHex[1] |= (byte)(this.AdditionalOption & 3);

			this.ItemHex[2] = (byte)this.ItemDurability;

			if (this.Serial == 0)
			{
				try
				{
					OleDbCommand cmd = new OleDbCommand("dbo.WZ_GetItemSerial", Import.Mu_Connection);

					cmd.CommandType = CommandType.StoredProcedure;

					int result = -1;

					using (OleDbDataReader reader = cmd.ExecuteReader())
					{
						if (reader.Read())
						{
							result = (int)reader.GetValue(0);
						}

						reader.Close();
					}

					if (result == -1)
					{
						this.Serial = 0;
					}
					else
					{
						this.Serial = (uint)result;
					}
				}
				catch (Exception exception)
				{
					MessageBox.Show("SQL：WZ_GetItemSerial.\nError:" + exception.Message + "\nSource:" + exception.Source + "\nTrace:" + exception.StackTrace, "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
				}
			}

			Buffer.BlockCopy(BitConverter.GetBytes(this.Serial), 0, this.ItemHex, 3, 4);

			this.ItemHex[7] = 0;
			this.ItemHex[7] |= (byte)(((this.Section * ItemManager.MAX_ITEM_TYPE + this.Index) & 256) >> 1);
			this.ItemHex[7] |= (byte)((this.AdditionalOption > 3) ? 64 : 0);
			this.ItemHex[7] |= (byte)this.ExcellentOption;

			this.ItemHex[8] = 0;

			this.ItemHex[9] = 0;
			this.ItemHex[9] |= (byte)(((this.Section * ItemManager.MAX_ITEM_TYPE + this.Index) & ItemManager.GET_ITEM(15, 0)) >> 5);

			return this.ItemHex;
		}
	}
}