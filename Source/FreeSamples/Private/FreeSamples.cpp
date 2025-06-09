#include "FreeSamples.h"
#include "Data/FreeSamplePlayerDataComponent.h"
#include "Patching/NativeHookManager.h"
#include "FGPlayerState.h"

#define LOCTEXT_NAMESPACE "FFreeSamplesModule"

DEFINE_LOG_CATEGORY(LogFreeSamplesCpp);

void OnFgCopyProperties(CallScope<void(*)(AFGPlayerState*, APlayerState*)>& scope, AFGPlayerState* self, APlayerState* playerState) {
	UE_LOG(LogFreeSamplesCpp, VeryVerbose, TEXT("OnFgCopyProperties hook"));
	if (auto component = self->GetComponentByClass<UFreeSamplePlayerDataComponent>()) {
		component->CopyProperties(playerState);
	} else {
		UE_LOG(LogFreeSamplesCpp, Warning, TEXT("OnFgCopyProperties PlayerState had no UFreeSamplePlayerDataComponent"));
	}

	scope(self, playerState);
}

//void OnCopyProperties(CallScope<void(*)(APlayerState*, APlayerState*)>& scope, APlayerState* self, APlayerState* playerState) {
//	UE_LOG(LogFreeSamplesCpp, VeryVerbose, TEXT("CopyProperties hook"));
//	scope(self, playerState);
//}

void OnDispatchOverrideWith(CallScope<void(*)(APlayerState*, APlayerState*)>& scope, APlayerState* self, APlayerState* playerState) {
	UE_LOG(LogFreeSamplesCpp, VeryVerbose, TEXT("OnDispatchOverrideWith hook"));
	if (auto component = self->GetComponentByClass<UFreeSamplePlayerDataComponent>()) {
		component->OverrideWith(playerState);
	} else {
		UE_LOG(LogFreeSamplesCpp, Warning, TEXT("OnDispatchOverrideWith PlayerState had no UFreeSamplePlayerDataComponent"));
	}

	scope(self, playerState);
}

void ApplyPlayerStateHooks() {
	// TODO once SF 1.1 is released there will be a nice bp-accessible entry point for this and we won't have to hook it from c++

	//AFGPlayerState* SampleObject1 = GetMutableDefault<AFGPlayerState>();
	//SUBSCRIBE_METHOD_VIRTUAL(AFGPlayerState::CopyProperties, SampleObject1, &OnFgCopyProperties);

	//APlayerState* SampleObject2 = GetMutableDefault<APlayerState>();
	////SUBSCRIBE_METHOD_VIRTUAL(APlayerState::DispatchCopyProperties, SampleObject2, &OnCopyProperties);
	//SUBSCRIBE_METHOD_VIRTUAL(APlayerState::DispatchOverrideWith, SampleObject2, &OnDispatchOverrideWith);
}

void FFreeSamplesModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
#if !WITH_EDITOR
	ApplyPlayerStateHooks();
#endif
}

void FFreeSamplesModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFreeSamplesModule, FreeSamples)