#include "photoStoryNewForm.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Io;
using namespace Tizen::Content;


photoStoryNewForm::photoStoryNewForm(void)
	: pEditTitle(null)
	, pEditStory(null)
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

	pEditTitle = static_cast<EditField*>(GetControl(IDC_TEXTBOX_TITLE));
	pEditTitle->Clear();
//	if (pEditTitle != null)
//	{
//		pEditTitle->AddTextEventListener(*this);
//	}

	pEditStory = static_cast<EditArea*>(GetControl(IDC_TEXTBOX_STORY));
	pEditStory->Remove();

	Button *pButtonAdd = static_cast<Button*>(GetControl(IDC_BUTTON_SAVE));
	if (pButtonAdd != null)
	{
		pButtonAdd->SetActionId(ID_BUTTON_SAVE);
		pButtonAdd->AddActionEventListener(*this);
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
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	switch(actionId)
	{
		case ID_BUTTON_SAVE: {
			AppLogTag("cantata", "Save New PhotoStory");
	//		ContentManager contentManager;
	//		contentManager.Construct();
	//
	//		ImageContentInfo imageContentInfo;
	//		imageContentInfo.Construct(null);
	//
	//
			AppLogTag("cantata", "Create File");
			String title = pEditTitle->GetText();

			if(title.IsEmpty())
			{
				return ;
			}
			AppLogTag("cantata", "Create File1");
			String filePath = App::GetInstance()->GetAppDataPath() + title + L".pts";
			AppLogTag("cantata", "Create File2");
			File file;
			result r = file.Construct(filePath, "w+");

			if (IsFailed(r))
				{
					AppLog("File::Construct() is failed by %s", GetErrorMessage(r));
				}

				r = file.Write(pEditStory->GetText());
				if (IsFailed(r))
				{
					AppLog("File::Write() is failed by %s", GetErrorMessage(r));
				}

				 ContentId contentId;
				        ContentManager contentManager;
				        r = contentManager.Construct();
//				        TryReturn(!IsFailed(r), r, "Construct failed.");

				        OtherContentInfo otherContentInfo;
				        r = otherContentInfo.Construct(null);
//				        TryReturn(!IsFailed(r), r, "Construct failed.");

//				        Tizen::Base::String sourcePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/flower.doc";
				        Tizen::Base::String destPath = Tizen::System::Environment::GetMediaPath() + L"Others/" + title + L".pts";

				        contentId = contentManager.CreateContent(filePath, destPath, false, &otherContentInfo);
//				        TryReturn(Tizen::Base::UuId::GetInvalidUuId() != contentId, GetLastResult(), "CreateContent failed.");



//			pSceneManager->GoForward(ForwardSceneTransition(SCENE_PHOTOSTORY_MAIN, SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
			pSceneManager->GoBackward(BackwardSceneTransition());
			break;
		}

		default:
			break;
	}
}

void
photoStoryNewForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition());
}

//void
//photoStoryNewForm::OnTextValueChanged(const Tizen::Ui::Control& source)
//{
//}
//
//void
//photoStoryNewForm::OnTextValueChangeCanceled(const Tizen::Ui::Control& source)
//{
//
//}

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
