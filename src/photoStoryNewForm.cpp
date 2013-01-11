#include <FApp.h>
#include "ResourceAfx.h"
#include "photoStoryNewForm.h"
#include <stdlib.h>

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


photoStoryNewForm::photoStoryNewForm(void)
{
}

photoStoryNewForm::~photoStoryNewForm(void)
{
}

bool
photoStoryNewForm::Initialize()
{
	Form::Construct(IDL_PHOTOSTORY_NEW);

	return true;
}

result
photoStoryNewForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	TextBox *pText_story = static_cast<TextBox *>(GetControl("text_Story"));  
	if(pText_story)
	{
		pText_story->AddTouchEventListener(*this);
	}
	return r;
}

result
photoStoryNewForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
photoStoryNewForm::OnTextBlockSelected(Tizen::Ui::Control& source, int start, int end)
{
	// TODO: Add your implementation codes here

}

void
photoStoryNewForm::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryNewForm::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryNewForm::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryNewForm::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryNewForm::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryNewForm::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryNewForm::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}
