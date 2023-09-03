#include "FreeSamplesBPLib.h"

#include "FreeSamples.h"
#include "Reflection/ReflectionHelper.h"

void UFreeSamplesBPLib::ReflectionTesting(TSubclassOf<UObject> clazz) {
	UE_LOG(LogFreeSamplesCpp, Warning, TEXT("Analyzing class %s"), *clazz->GetName());
	
	for (TFieldIterator<FProperty> Property(clazz); Property; ++Property) {
		UE_LOG(LogFreeSamplesCpp, Warning, TEXT("    Has property: %s"), *Property->GetName());
	}
	for (TFieldIterator<UFunction> Function(clazz); Function; ++Function) {
		UE_LOG(LogFreeSamplesCpp, Warning, TEXT("    Has function: %s"), *Function->GetName());
	}
}


TArray<TSoftClassPtr<UObject>> UFreeSamplesBPLib::ArrayReflectionTesting(TSubclassOf<UObject> clazz) {
	UE_LOG(LogFreeSamplesCpp, Warning, TEXT("Analyzing class %s"), *clazz->GetName());
	TArray<TSoftClassPtr<UObject>> out;

	const auto cdo = clazz->GetDefaultObject();

	if (!cdo) {
		UE_LOG(LogFreeSamplesCpp, Error, TEXT("class CDO invalid?"));
		return out;
	} else {
		UE_LOG(LogFreeSamplesCpp, Warning, TEXT("class CDO is %s"), *cdo->GetName());
	}

	// Could switch to this instead of loop, but not sure how to get the struct it wants
	// FReflectionHelper::FindPropertyChecked(temp, TEXT("FreeSamples_SkipSchematics"));

	bool found = false;
	for (TFieldIterator<FArrayProperty> arrProp(clazz); arrProp; ++arrProp) {
		if (arrProp->GetName().Equals(TEXT("FreeSamples_SkipSchematics"))) {
			found = true;
			UE_LOG(LogFreeSamplesCpp, Warning, TEXT("Found FreeSamples_SkipSchematics"));

			const FArrayProperty* property = *arrProp;
			const void* context = arrProp->ContainerPtrToValuePtr<void>(cdo);
			FScriptArrayHelper SArr = FScriptArrayHelper(property, context);

			FSoftClassProperty* innerType = CastField<FSoftClassProperty>(arrProp->Inner);

			UE_LOG(LogFreeSamplesCpp, Warning, TEXT("Num: %d"), SArr.Num());

			for (int index = 0; index < SArr.Num(); ++index) {
				UE_LOG(LogFreeSamplesCpp, Warning, TEXT("Entry %d"), index);
				FSoftObjectPtr rawValue = innerType->GetPropertyValue_InContainer(SArr.GetRawPtr(index));
				FSoftObjectPath softPath = rawValue.ToSoftObjectPath();
				const auto& toAdd = TSoftClassPtr<UObject>(softPath);
				out.Add(toAdd);
			}
			return out;
		}
	}

	if (!found) {
		UE_LOG(LogFreeSamplesCpp, Warning, TEXT("Field FreeSamples_SkipSchematics not found"));
	}
	return out;
}

TArray<TSoftClassPtr<UObject>> UFreeSamplesBPLib::GetArbitrarySoftClassArray(bool& out_Success, FName propertyName, UObject* onObject) {
	TArray<TSoftClassPtr<UObject>> out;
	if (!onObject) {
		UE_LOG(LogFreeSamplesCpp, Error, TEXT("Passed onObject is invalid"));
		return out;
	}
	if (propertyName.IsNone()) {
		UE_LOG(LogFreeSamplesCpp, Error, TEXT("Passed propertyName is invalid"));
		return out;
	}

	// Could switch to this instead of loop, but not sure how to get the struct it wants
	// FReflectionHelper::FindPropertyChecked(temp, propertyName);
	bool found = false;
	for (TFieldIterator<FArrayProperty> arrProp(onObject->GetClass()); arrProp; ++arrProp) {
		if (arrProp->GetName().Equals(propertyName.ToString())) {
			found = true;

			const void* context = arrProp->ContainerPtrToValuePtr<void>(onObject);
			FScriptArrayHelper SArr = FScriptArrayHelper(*arrProp, context);
			FSoftClassProperty* innerType = CastField<FSoftClassProperty>(arrProp->Inner);

			for (int index = 0; index < SArr.Num(); ++index) {
				FSoftObjectPtr rawValue = innerType->GetPropertyValue_InContainer(SArr.GetRawPtr(index));
				FSoftObjectPath softPath = rawValue.ToSoftObjectPath();
				const auto& toAdd = TSoftClassPtr<UObject>(softPath);
				out.Add(toAdd);
			}
			out_Success = true;
			return out;
		}
	}

	if (!found) {
		UE_LOG(LogFreeSamplesCpp, Error, TEXT("FArrayProperty field '%s' not found on %s"), *propertyName.ToString(), *onObject->GetName());
	}
	return out;
}

TMap<TSoftClassPtr<UObject>, int> UFreeSamplesBPLib::GetArbitrarySoftClassIntMap(bool& out_Success, FName propertyName, UObject* onObject) {
	TMap<TSoftClassPtr<UObject>, int> out;
	if (!onObject) {
		UE_LOG(LogFreeSamplesCpp, Error, TEXT("Passed onObject is invalid"));
		return out;
	}
	if (propertyName.IsNone()) {
		UE_LOG(LogFreeSamplesCpp, Error, TEXT("Passed propertyName is invalid"));
		return out;
	}

	// Could switch to this instead of loop, but not sure how to get the struct it wants
	// FReflectionHelper::FindPropertyChecked(temp, propertyName);
	bool found = false;
	for (TFieldIterator<FMapProperty> mapProp(onObject->GetClass()); mapProp; ++mapProp) {
		if (mapProp->GetName().Equals(propertyName.ToString())) {
			found = true;

			const void* context = mapProp->ContainerPtrToValuePtr<void>(onObject);
			FScriptMapHelper SMap = FScriptMapHelper(*mapProp, context);

			const FSoftClassProperty* keyProp = CastField<FSoftClassProperty>(mapProp->GetKeyProperty());
			const FIntProperty* valueProp = CastField<FIntProperty>(mapProp->GetValueProperty());

			for (int index = 0; index < SMap.Num(); ++index) {
				auto& rawKey = keyProp->GetPropertyValue_InContainer(SMap.GetPairPtr(index));
				auto& rawValue = valueProp->GetPropertyValue_InContainer(SMap.GetPairPtr(index));

				const auto& keyToAdd = TSoftClassPtr<UObject>(rawKey.ToSoftObjectPath());
				const auto& valueToAdd = rawValue;
				auto const entryToAdd = TTuple<TSoftClassPtr<UObject>, int>(keyToAdd, valueToAdd);
				out.Add(entryToAdd);
			}
			out_Success = true;
			return out;
		}
	}

	if (!found) {
		UE_LOG(LogFreeSamplesCpp, Error, TEXT("FMapProperty field '%s' not found on %s"), *propertyName.ToString(), *onObject->GetName());
	}
	return out;
}

bool UFreeSamplesBPLib::HasProperty(FName propertyName, UObject* onObject) {
	if (!onObject) {
		UE_LOG(LogFreeSamplesCpp, Error, TEXT("Passed onObject is invalid"));
		return false;
	}
	if (propertyName.IsNone()) {
		UE_LOG(LogFreeSamplesCpp, Error, TEXT("Passed propertyName is invalid"));
		return false;
	}
	return onObject->GetClass()->FindPropertyByName(propertyName)->IsValidLowLevel();
}
