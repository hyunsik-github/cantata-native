/*
 * PhotoStoryList.h
 *
 *  Created on: Jan 9, 2013
 *      Author: hyunsik
 */
#include <FBase.h>
#include <FUi.h>

#ifndef PHOTOSTORYLIST_H_
#define PHOTOSTORYLIST_H_

class PhotoStoryList
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::ITextBlockEventListener
	, public Tizen::Ui::ITouchEventListener
{
public:
	PhotoStoryList();
	virtual ~PhotoStoryList();
	bool Initialize();
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

public :
	virtual void OnTextBlockSelected(Tizen::Ui::Control& source, int start, int end);
	virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
};

#endif /* PHOTOSTORYLIST_H_ */
