/*
 * photoStoryMainForm.cpp
 *
 *  Created on: Jan 9, 2013
 *      Author: hyunsik
 */
#include <FApp.h>
#include "cantata.h"
#include "ResourceAfx.h"
#include "photoStoryMainForm.h"
#include <stdlib.h>

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

photoStoryMainForm::photoStoryMainForm() {

}

photoStoryMainForm::~photoStoryMainForm() {
}

bool
photoStoryMainForm::Initialize()
{
	Form::Construct(IDL_PHOTOSTORY_MAIN);
	AppLogTag("cantata", "photoStoryMainForm Initialize");
	return true;
}

result
photoStoryMainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

//	TextBox *pText_story = static_cast<TextBox *>(GetControl("text_Story"));
//	if(pText_story)
//	{
//		pText_story->AddTouchEventListener(*this);
//	}

	Tizen::Ui::Controls::Button *pButtonAdd = static_cast<Button*>(GetControl(IDC_BUTTON_ADD));
	if (pButtonAdd != null)
	{
		pButtonAdd->SetActionId(ID_BUTTON_ADD);
		pButtonAdd->AddActionEventListener(*this);
		pButtonAdd->AddTouchEventListener(*this);
	}
	return r;
}

result
photoStoryMainForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
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
//		String appName = App::GetInstance()->GetAppRootPath() + App::GetInstance()->GetAppName();
//		String resPath = App::GetInstance()->GetAppResourcePath();
//		const wchar_t *pAppPath = (const wchar_t*)appName.GetPointer();
//		const wchar_t *pResPath = (const wchar_t*)resPath.GetPointer();
//		char app_path[512];
//		char res_path[512];
//		char js_path[512];
//		char node_path[512];
//		char command[512];
//
//		wcstombs(app_path, pAppPath, appName.GetLength()+1);
//		wcstombs(res_path, pResPath, resPath.GetLength()+1);
//		sprintf(node_path, "%s%s", res_path,"node");
//		sprintf(js_path, "%s%s", res_path,"app.js");
//
//		sprintf(command, "%s %s", node_path, js_path);
//		system(command);

		break;
	}

	default:
		break;
	}
}

void
photoStoryMainForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
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

void
photoStoryMainForm::OnTextBlockSelected(Tizen::Ui::Control& source, int start, int end)
{
	// TODO: Add your implementation codes here

}

void
photoStoryMainForm::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryMainForm::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryMainForm::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryMainForm::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryMainForm::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryMainForm::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
photoStoryMainForm::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}
