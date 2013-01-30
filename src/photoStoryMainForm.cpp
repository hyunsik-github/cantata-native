/*
 * photoStoryMainForm.cpp
 *
 *  Created on: Jan 9, 2013
 *      Author: hyunsik
 */
#include "cantata.h"
#include "photoStoryMainForm.h"


using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Content;
using namespace Tizen::Graphics;

photoStoryMainForm::photoStoryMainForm()
	: __pPhotoStoryListView(null)
	, __pSearchResultList(null)
	, __contentType(CONTENT_TYPE_OTHER)
{
	SearhPhotoStory();
}

photoStoryMainForm::~photoStoryMainForm() {
}

bool
photoStoryMainForm::Initialize()
{
	Form::Construct(IDL_PHOTOSTORY_MAIN);
	AppLogTag("cantata", "photoStoryMainForm Initialize");

//	TryReturn(__pPhotoStoryListView != null, false, "__pPhotoStoryListView is null.");

	return true;
}

result
photoStoryMainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Footer* pFooter = GetFooter();
	pFooter->AddActionEventListener(*this);
	SetFormBackEventListener(this);

	Rectangle rect = this->GetClientAreaBounds();

	ListView *__pPhotoStoryListView = static_cast<ListView *>(GetControl(IDC_LISTVIEW));

	__pPhotoStoryListView->SetTextOfEmptyList(L"No PhotoStory");
	__pPhotoStoryListView->SetItemProvider(*this);
	__pPhotoStoryListView->AddListViewItemEventListener(*this);

	AddControl(*__pPhotoStoryListView);

	Button *pButtonAdd = static_cast<Button*>(GetControl(IDC_BUTTON_ADD));
	if (pButtonAdd != null)
	{
		pButtonAdd->SetActionId(ID_BUTTON_ADD);
		pButtonAdd->AddActionEventListener(*this);
//		pButtonAdd->AddTouchEventListener(*this);
	}

	return r;
}

result
photoStoryMainForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	return r;
}

result
photoStoryMainForm::SearhPhotoStory(void)
{
	result r = E_SUCCESS;
	ContentSearch contentSearch;
	String sortColumn = L"";
	int totalPage = 0;
	int totalCount = 0;
	int page = 1;

	// Clear the previous result
	initResultList();

	r = contentSearch.Construct(__contentType);
	TryReturn(E_SUCCESS == r, r, "Construct() failed by %s.", GetErrorMessage(r));

//	strQuery = makeQuery(query);

	// execute
	__pSearchResultList = contentSearch.SearchN(page, 12, totalPage, totalCount, L"", sortColumn, SORT_ORDER_NONE);
	r = GetLastResult();
	TryReturn(__pSearchResultList != null, r, "ContentSearch.SearchN() failed by %s.", GetErrorMessage(r));

	return r;
}

void
photoStoryMainForm::initResultList(void)
{
	if (__pSearchResultList != null)
	{
		__pSearchResultList->RemoveAll(true);
		delete __pSearchResultList;
		__pSearchResultList = null;
	}
}

void
photoStoryMainForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	switch(actionId)
	{
	case ID_BUTTON_ADD: {
		AppLogTag("cantata", "Open New PhotoStory");
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_PHOTOSTORY_NEW, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));

		break;
	}

	default:
		break;
	}
}

void
photoStoryMainForm::OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state)
{

}

void
photoStoryMainForm::OnListViewItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status)
{

}

void
photoStoryMainForm::OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction)
{

}

void
photoStoryMainForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition());
}

ListItemBase*
photoStoryMainForm::CreateItem(int index, int itemWidth)
{
	AppLogTag("cantata", "Create Item");

	String contentFileName;

	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
	CustomItem* pItem = new (std::nothrow) CustomItem();
	TryReturn(pItem != null, pItem, "pItem is null.");

	pItem->Construct(Dimension(itemWidth, 50), style);

	contentFileName.Clear();

	contentFileName = GetContentFileName(index);

	pItem->AddElement(Rectangle(17, 0, itemWidth - 40, 50), 100, contentFileName);

	return pItem;
}

int
photoStoryMainForm::GetItemCount(void)
{
	int count = 0;

	if (__pSearchResultList != null)
		{
			count = __pSearchResultList->GetCount();
		}
	AppLogDebug("count: %d", count);

	return count;
}

bool
photoStoryMainForm::DeleteItem(int index, ListItemBase* pItem, int itemWidth)
{
	return true;
}

void
photoStoryMainForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	result r = E_SUCCESS;

	r = __pPhotoStoryListView->UpdateList();
	TryReturnVoid(!IsFailed(r), "UpdateList failed.");
}

void
photoStoryMainForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO:
	// Add your scene deactivate code here
	AppLog("OnSceneDeactivated");
}

//void
//photoStoryMainForm::OnTextBlockSelected(Tizen::Ui::Control& source, int start, int end)
//{
//	// TODO: Add your implementation codes here
//
//}
//
//void
//photoStoryMainForm::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
//{
//	// TODO: Add your implementation codes here
//
//}
//
//void
//photoStoryMainForm::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
//{
//	// TODO: Add your implementation codes here
//
//}
//
//void
//photoStoryMainForm::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
//{
//	// TODO: Add your implementation codes here
//
//}
//
//void
//photoStoryMainForm::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
//{
//	// TODO: Add your implementation codes here
//
//}
//
//void
//photoStoryMainForm::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
//{
//	// TODO: Add your implementation codes here
//
//}
//
//void
//photoStoryMainForm::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
//{
//	// TODO: Add your implementation codes here
//
//}
//
//void
//photoStoryMainForm::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
//{
//	// TODO: Add your implementation codes here
//
//}

String
photoStoryMainForm::GetContentFileName(int index) const
{
	String contentFullPath;
	String contentFileName;
	String delimeter = L"/";
	int filenamePos = 0;
	ContentSearchResult* pInfo = null;
	result r = E_SUCCESS;

	contentFileName.Clear();

	TryReturn(__pSearchResultList != null, contentFileName, "No search result");

	pInfo = (ContentSearchResult*)__pSearchResultList->GetAt(index);
	contentFullPath = ((ContentInfo*)pInfo->GetContentInfo())->GetContentPath();
	if (contentFullPath.IsEmpty() == false)
	{
		// eliminate a directory name from the ContentPath
		r = contentFullPath.LastIndexOf(delimeter, contentFullPath.GetLength() - 1, filenamePos);
		if (r == E_SUCCESS && filenamePos > 0)
		{
			r = contentFullPath.SubString(filenamePos + 1, contentFileName);
			if (r != E_SUCCESS)
			{
				contentFileName = contentFullPath;
			}
		}
		else
		{
			contentFileName = contentFullPath;
		}
	}

    return contentFileName;
}
