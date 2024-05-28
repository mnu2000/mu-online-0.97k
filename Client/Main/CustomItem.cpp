#include "stdafx.h"
#include "CustomItem.h"

CCustomItem gCustomItem;

CCustomItem::CCustomItem()
{
	this->Init();
}

CCustomItem::~CCustomItem()
{

}

void CCustomItem::Init()
{
	for (int n = 0; n < MAX_ITEM; n++)
	{
		this->m_CustomItemInfo[n].ItemIndex = -1;
	}
}

void CCustomItem::Load(CUSTOM_ITEM_INFO* info)
{
	for (int n = 0; n < MAX_ITEM; n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomItem::SetInfo(CUSTOM_ITEM_INFO info)
{
	if (info.ItemIndex < 0 || info.ItemIndex >= MAX_ITEM)
	{
		return;
	}

	this->m_CustomItemInfo[info.ItemIndex] = info;
}

CUSTOM_ITEM_INFO* CCustomItem::GetInfoByItem(int ItemIndex)
{
	if (ItemIndex < 0 || ItemIndex >= MAX_ITEM)
	{
		return 0;
	}

	if (this->m_CustomItemInfo[ItemIndex].ItemIndex != ItemIndex)
	{
		return 0;
	}

	return &this->m_CustomItemInfo[ItemIndex];
}

BYTE CCustomItem::GetCustomItemSkill(int ItemIndex)
{
	CUSTOM_ITEM_INFO* lpInfo = this->GetInfoByItem(ItemIndex);

	if (lpInfo != 0)
	{
		return lpInfo->SkillNumber;
	}

	return (BYTE)0xFF;
}