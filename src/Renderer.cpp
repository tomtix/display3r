#include <tuple>
#include <utility>

#include "display3r/Renderer.hpp"
#include "display3r/Window.hpp"

using std::vector;
using display3r::Renderer;
using display3r::ZBuffer;

Renderer::Renderer(Window *window):
    m_lens(NULL), m_window(window), m_untexturedColor(0, 255, 255)
{
    Resize(m_window->GetWidth(), m_window->GetHeight());
}

void Renderer::Clear()
{
    m_window->Clear();
    m_zbuf.Clear();
}

void Renderer::BindTexture(Texture *texture)
{
    m_texture = texture;
}

void Renderer::BindLights(vector<Light> *lights)
{
    m_lights = lights;
}

void Renderer::Resize(int width, int height)
{
    m_zbuf.Resize(width, height);
}

void ZBuffer::Clear()
{
    union { int i; float f; } v = {.f = -1.0 };
    memset(&m_buf[0], v.i, m_buf.size());
}

void ZBuffer::Resize(int width, int height)
{
    m_buf.resize(width*height);
}

void Renderer::SetLens(Lens const *lens)
{
    m_lens = lens;
    m_nearplan = lens->GetNearPlan();
    m_width = lens->GetWindowWidth();
    m_height = lens->GetWindowHeight();
    m_wfov = lens->GetHFov();
    m_hfov = lens->GetWFov();

    // lens->ConfigureZBuffer(m_zbuf);
}

void Renderer::SetColor(Color const &drawColor)
{
    m_drawColor = drawColor;
}

void Renderer::SetDrawState(Renderer::DrawState drawState)
{
    m_drawState = drawState;
}

void Renderer::PushState()
{
    m_states.push(std::make_pair(m_drawState, m_drawColor));
}

void Renderer::PopState()
{
    std::tie(m_drawState, m_drawColor) = m_states.top();
    m_states.pop();
}
