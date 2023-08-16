#include "Subsystem/FreeSamplesSubsystem.h"

bool AFreeSamplesSubsystem::PlayerClaimSamples_Implementation(bool manuallyTriggered, APlayerState* player) {
	UE_LOG(LogFreeSamplesCpp, Error, TEXT("No C++ implementation yet for PlayerClaimSamples_Implementation, make sure this is overridden in Blueprint"));
	return false;
}

AFreeSamplesSubsystem* AFreeSamplesSubsystem::Get(UObject* WorldContext) {
	if (!WorldContext) {
		return nullptr;
	}
	if (WorldContext->GetWorld()) {
		TArray<AActor*> arr;
		// Relies on the fact that nothing has spawned the C++ version before
		UGameplayStatics::GetAllActorsOfClass(WorldContext->GetWorld(), AFreeSamplesSubsystem::StaticClass(), arr);
		if (arr.IsValidIndex(0)) {
			AFreeSamplesSubsystem* out = Cast<AFreeSamplesSubsystem>(arr[0]);
			return out;
		} else {
			return nullptr;
		}
	} else {
		return nullptr;
	}
}
