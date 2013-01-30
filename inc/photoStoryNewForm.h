
#ifndef _PHOTOSTORYNEWFORM_H_
#define _PHOTOSTORYNEWFORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>
#include <FIo.h>
#include <FContent.h>
#include <stdlib.h>

#include "cantata.h"
#include "ResourceAfx.h"



class photoStoryNewForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
//	, public Tizen::Ui::ITextEventListener
 	, public Tizen::Ui::ITextBlockEventListener
 	, public Tizen::Ui::ITouchEventListener
{

// Construction
public:
	photoStoryNewForm(void);
	virtual ~photoStoryNewForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
//	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
//			const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
//	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
//			const Tizen::Ui::Scenes::SceneId& nextSceneId);

	// ITextEventListener
//	virtual void OnTextValueChanged(const Tizen::Ui::Control& source);
//	virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source);


// Implementation
protected:

// Generated call-back functions
public:

	virtual void OnTextBlockSelected(Tizen::Ui::Control& source, int start, int end);
	virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);

public:
	static const int ID_BUTTON_SAVE = 211;
	static const int ID_BUTTON_CANCEL = 212;

private:
	Tizen::Ui::Controls::EditField *pEditTitle;
	Tizen::Ui::Controls::EditArea *pEditStory;
};

#endif
