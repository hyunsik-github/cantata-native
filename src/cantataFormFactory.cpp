#include "cantataFormFactory.h"
#include "cantataMainForm.h"
#include "NewPhotoStory.h"
#include "PhotoStoryList.h"
#include "ResourceAfx.h"

using namespace Tizen::Ui::Scenes;

const wchar_t* FORM_NEWPHOTOSTORY = L"Form_NewPhotoStory";
const wchar_t* FORM_PHOTOSTORYLIST = L"Form_PhotoStoryList";

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

	if (formId == L"MainForm")
	{
		cantataMainForm* pForm = new cantataMainForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	if (formId == IDL_PhotoStoryList)
	{
		PhotoStoryList* pPhotoStoryList = new PhotoStoryList();
		pPhotoStoryList->Initialize();
//		pSceneManager->AddSceneEventListener(sceneId, *pPhotoStoryList);
		pNewForm = pPhotoStoryList;
	}
	if (formId == IDL_NewPhotoStory)
	{
		NewPhotoStory* pNewPhotoStory = new NewPhotoStory();
		pNewPhotoStory->Initialize();
//		pSceneManager->AddSceneEventListener(sceneId, *pNewPhotoStory);
		pNewForm = pNewPhotoStory;
	}
	// TODO:
	// Add your form creation code here

	return pNewForm;
}
