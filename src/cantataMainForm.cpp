#include <FApp.h>
#include "cantataMainForm.h"
#include "ResourceAfx.h"
#include <stdlib.h>

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

cantataMainForm::cantataMainForm(void)
{
}

cantataMainForm::~cantataMainForm(void)
{
}

bool
cantataMainForm::Initialize(void)
{
	Construct(L"CANTATAMAIN_FORM");
	AppLogTag("cantataMainForm", "cantataMainForm::Initialize");
	return true;
}

result
cantataMainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO:
	// Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	Tizen::Ui::Controls::Button *pButtonOk = static_cast<Button*>(GetControl(IDC_BUTTON_OK));
	if (pButtonOk != null)
	{
		pButtonOk->SetActionId(ID_BUTTON_OK);
		pButtonOk->AddActionEventListener(*this);
		pButtonOk->AddTouchEventListener(*this);
	}

//	Button *pBtnadd = static_cast<Button *>(GetControl(IDC_BUTTON_ADD));
//	if(pBtnadd)
//	{
//		pBtnadd->SetActionId(ID_BUTTON_ADD);
//		pBtnadd->AddActionEventListener(*this);
//		pBtnadd->AddTouchEventListener(*this);
//	}
	return r;
}

result
cantataMainForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO:
	// Add your termination code here
	return r;
}

void
cantataMainForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	switch(actionId)
	{
	case ID_BUTTON_OK: {
		AppLogTag("cantata", "Open PhotoStoryList");
		pSceneManager->GoForward(ForwardSceneTransition(IDL_PhotoStoryList));
		pSceneManager->GoForward(ForwardSceneTransition(IDL_PhotoStoryList, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
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
cantataMainForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
cantataMainForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO:
	// Add your scene activate code here
	AppLog("OnSceneActivatedN");
}

void
cantataMainForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO:
	// Add your scene deactivate code here
	AppLog("OnSceneDeactivated");
}


void
cantataMainForm::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
cantataMainForm::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
cantataMainForm::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
cantataMainForm::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
cantataMainForm::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
cantataMainForm::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
cantataMainForm::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}
