﻿#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#define SKIP_ALL_CUSTOM_SERIALIZE true

class FKettisLogicDriverGASModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
