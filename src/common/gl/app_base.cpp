/**
 * Copyright (c) Aleksey Fedotov
 * MIT licence
 */

#include "./app_base.h"
#include "./window.h"

gl::AppBase::AppBase(uint32_t canvasWidth, uint32_t canvasHeight, bool fullScreen) : ::AppBase(std::make_unique<gl::Window>(canvasWidth, canvasHeight, "Demo", fullScreen))
{
}
