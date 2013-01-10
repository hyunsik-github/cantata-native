/*
 * PhotoStoryList.cpp
 *
 *  Created on: Jan 9, 2013
 *      Author: hyunsik
 */

#include "ResourceAfx.h"
#include "PhotoStoryList.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

PhotoStoryList::PhotoStoryList() {

}

PhotoStoryList::~PhotoStoryList() {
}

bool
PhotoStoryList::Initialize()
{
	Form::Construct(IDL_PhotoStoryList);
	AppLogTag("cantata", "PhotoStoryList Initialize");
	return true;
}

result
PhotoStoryList::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

//	TextBox *pText_story = static_cast<TextBox *>(GetControl("text_Story"));
//	if(pText_story)
//	{
//		pText_story->AddTouchEventListener(*this);
//	}
	return r;
}

result
PhotoStoryList::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
PhotoStoryList::OnTextBlockSelected(Tizen::Ui::Control& source, int start, int end)
{
	// TODO: Add your implementation codes here

}

void
PhotoStoryList::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
PhotoStoryList::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
PhotoStoryList::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
PhotoStoryList::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
PhotoStoryList::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
PhotoStoryList::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
PhotoStoryList::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}
