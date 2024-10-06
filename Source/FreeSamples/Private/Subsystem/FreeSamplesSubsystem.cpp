#include "Subsystem/FreeSamplesSubsystem.h"

bool AFreeSamplesSubsystem::PlayerClaimSamples_Implementation(bool manuallyTriggered, APlayerState* player, bool dropExcessOnGround) {
	UE_LOG(LogFreeSamplesCpp, Error, TEXT("No C++ implementation yet for PlayerClaimSamples_Implementation, make sure this is overridden in Blueprint"));
	return false;
}

AFreeSamplesSubsystem* AFreeSamplesSubsystem::Get(UWorld* world) {
	USubsystemActorManager* SubsystemActorManager = world->GetSubsystem<USubsystemActorManager>();
	fgcheck(SubsystemActorManager);

	AFreeSamplesSubsystem* freeSamplesSubsystem = SubsystemActorManager->GetSubsystemActor<AFreeSamplesSubsystem>();
	fgcheck(freeSamplesSubsystem);

	return freeSamplesSubsystem;
}
