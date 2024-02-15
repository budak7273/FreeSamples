#include "Subsystem/FreeSamplesSubsystem.h"

bool AFreeSamplesSubsystem::PlayerClaimSamples_Implementation(bool manuallyTriggered, APlayerState* player, bool dropExcessOnGround) {
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
		// The blueprint one descends from this so it is found instead
		// This would break if a C++ version was spawned or persisted via save game
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
