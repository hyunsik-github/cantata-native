#include "cantataFormFactory.h"
#include "cantataMainForm.h"
#include "photoStoryMainForm.h"
#include "photoStoryNewForm.h"
#include "ResourceAfx.h"

using namespace Tizen::Ui::Scenes;

const wchar_t* FORM_CANTATA = L"Form_Cantata";

const wchar_t* FORM_PHOTOSTORY_MAIN = L"Form_PhotoStory_Main";
const wchar_t* FORM_PHOTOSTORY_NEW = L"Form_PhotoStory_New";


cantataFormFactory::cantataFormFactory(void)
{
}

cantataFormFactory::~cantataFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
cantataFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == FORM_CANTATA)
	{
		cantataMainForm* pForm = new cantataMainForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	if (formId == FORM_PHOTOSTORY_MAIN)
	{
		photoStoryMainForm* pFormPhotoStoryMain = new photoStoryMainForm();
		pFormPhotoStoryMain->Initialize();
//		pSceneManager->AddSceneEventListener(sceneId, *pFormPhotoStoryMain);
		pNewForm = pFormPhotoStoryMain;
	}
	if (formId == FORM_PHOTOSTORY_NEW)
	{
		photoStoryNewForm* pFormPhotoStoryNew = new photoStoryNewForm();
		pFormPhotoStoryNew->Initialize();
//		pSceneManager->AddSceneEventListener(sceneId, *pFormPhotoStoryNew);
		pNewForm = pFormPhotoStoryNew;
	}
	// TODO:
	// Add your form creation code here

	return pNewForm;
}
