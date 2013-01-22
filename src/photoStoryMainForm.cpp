/*
 * photoStoryMainForm.cpp
 *
 *  Created on: Jan 9, 2013
 *      Author: hyunsik
 */
#include "cantata.h"
#include "photoStoryMainForm.h"


using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Content;
using namespace Tizen::Graphics;

photoStoryMainForm::photoStoryMainForm()
	: __pPhotoStoryListView(null)
	, __pSearchResultList(null)
	, __contentType(CONTENT_TYPE_IMAGE)
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

	__pPhotoStoryListView = new IconListView();
	TryReturn(__pPhotoStoryListView != null, false, "__pPhotoStoryListView is null.");

	return true;
}

result
photoStoryMainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Footer* pFooter = GetFooter();
	pFooter->AddActionEventListener(*this);
	SetFormBackEventListener(this);

	__pPhotoStoryListView->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height), Dimension(100, 100), ICON_LIST_VIEW_STYLE_NORMAL, ICON_LIST_VIEW_SCROLL_DIRECTION_VERTICAL);

	__pPhotoStoryListView->SetTextOfEmptyList(L"No PhotoStory");
	__pPhotoStoryListView->SetItemProvider(*this);
	__pPhotoStoryListView->AddIconListViewItemEventListener(*this);

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
OnIconListViewItemStateChanged(Tizen::Ui::Controls::IconListView& iconListView, int index, Tizen::Ui::Controls::IconListViewItemStatus status)
{
}

void
photoStoryMainForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition());
}

IconListViewItem*
photoStoryMainForm::CreateItem(int index)
{
	return null;
}

int
photoStoryMainForm::GetItemCount(void)
{
	return 0;
}

bool
photoStoryMainForm::DeleteItem(int index, IconListViewItem* pItem)
{
	return true;
}

void
photoStoryMainForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO:
	// Add your scene activate code here
	AppLog("OnSceneActivatedN");
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
