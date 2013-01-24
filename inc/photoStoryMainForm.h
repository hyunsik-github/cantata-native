/*
 * photoStoryMainForm.h
 *
 *  Created on: Jan 9, 2013
 *      Author: hyunsik
 */
#include <FBase.h>
#include <FUi.h>
#include <FApp.h>
#include <FContent.h>

#include "ResourceAfx.h"

#ifndef PHOTOSTORYMAINFORM_H_
#define PHOTOSTORYMAINFORM_H_

class photoStoryMainForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IIconListViewItemEventListener
	, public Tizen::Ui::Controls::IIconListViewItemProvider
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
//	, public Tizen::Ui::ITextBlockEventListener
//	, public Tizen::Ui::ITouchEventListener
{
public:
	photoStoryMainForm();
	virtual ~photoStoryMainForm();
	bool Initialize();
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
			const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
			const Tizen::Ui::Scenes::SceneId& nextSceneId);
	//IIconListViewItemEventListener
	virtual void OnIconListViewItemStateChanged(Tizen::Ui::Controls::IconListView& iconListView, int index, Tizen::Ui::Controls::IconListViewItemStatus status);
	virtual void OnIconListViewOverlayBitmapSelected(Tizen::Ui::Controls::IconListView& iconListView, int index, int overlayBitmapId);
	virtual void OnIconListViewItemReordered(Tizen::Ui::Controls::IconListView&  iconListView, int indexFrom, int indexTo);

	//IIconListViewItemProvider
	virtual int GetItemCount(void);
	virtual Tizen::Ui::Controls::IconListViewItem* CreateItem(int index);
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::IconListViewItem* pItem);


protected:
	static const int ID_BUTTON_ADD = 201;

//	virtual void OnTextBlockSelected(Tizen::Ui::Control& source, int start, int end);
//	virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
//	virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
//	virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
//	virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
//	virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
//	virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
//	virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);

private:
	result SearhPhotoStory(void);
	void initResultList(void);

private:
	Tizen::Ui::Controls::IconListView* __pPhotoStoryListView;
	Tizen::Base::Collection::IList* __pSearchResultList;
	Tizen::Content::ContentType __contentType;
};

#endif /* photoStoryMainForm_H_ */
