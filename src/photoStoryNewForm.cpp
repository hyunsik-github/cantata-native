#include "photoStoryNewForm.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


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
	SetFormBackEventListener(this);

	// TODO: Add your initialization code here
	Footer* pFooter = GetFooter();
	pFooter->AddActionEventListener(*this);

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
photoStoryNewForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
//	SceneManager* pSceneManager = SceneManager::GetInstance();
//	AppAssert(pSceneManager);
//	switch(actionId)
//	{
//	case ID_BUTTON_ADD: {
//		AppLogTag("cantata", "Open New PhotoStory");
//		pSceneManager->GoForward(ForwardSceneTransition(SCENE_PHOTOSTORY_NEW, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
////		String appName = App::GetInstance()->GetAppRootPath() + App::GetInstance()->GetAppName();
////		String resPath = App::GetInstance()->GetAppResourcePath();
////		const wchar_t *pAppPath = (const wchar_t*)appName.GetPointer();
////		const wchar_t *pResPath = (const wchar_t*)resPath.GetPointer();
////		char app_path[512];
////		char res_path[512];
////		char js_path[512];
////		char node_path[512];
////		char command[512];
////
////		wcstombs(app_path, pAppPath, appName.GetLength()+1);
////		wcstombs(res_path, pResPath, resPath.GetLength()+1);
////		sprintf(node_path, "%s%s", res_path,"node");
////		sprintf(js_path, "%s%s", res_path,"app.js");
////
////		sprintf(command, "%s %s", node_path, js_path);
////		system(command);
//
//		break;
//	}
//
//	default:
//		break;
//	}
}

void
photoStoryNewForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition());
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
