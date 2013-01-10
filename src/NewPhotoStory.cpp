#include <FApp.h>
#include "ResourceAfx.h"
#include "NewPhotoStory.h"
#include <stdlib.h>

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


NewPhotoStory::NewPhotoStory(void)
{
}

NewPhotoStory::~NewPhotoStory(void)
{
}

bool
NewPhotoStory::Initialize()
{
	Form::Construct(IDL_NewPhotoStory);

	return true;
}

result
NewPhotoStory::OnInitializing(void)
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
NewPhotoStory::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
NewPhotoStory::OnTextBlockSelected(Tizen::Ui::Control& source, int start, int end)
{
	// TODO: Add your implementation codes here

}

void
NewPhotoStory::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
NewPhotoStory::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
NewPhotoStory::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
NewPhotoStory::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
NewPhotoStory::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
NewPhotoStory::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
NewPhotoStory::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}
