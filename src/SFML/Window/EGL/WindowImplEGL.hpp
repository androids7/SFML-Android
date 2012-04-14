////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
// Copyright (C) 2012  Sylvain Beucler
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_WINDOWIMPLEGL_HPP
#define SFML_WINDOWIMPLEGL_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowImpl.hpp>
#include <string>


namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
/// WindowImplEGL is the EGL implementation of WindowImpl
////////////////////////////////////////////////////////////
class WindowImplEGL : public WindowImpl
{
public :
    ////////////////////////////////////////////////////////////
    /// Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~WindowImplEGL();

    ////////////////////////////////////////////////////////////
    /// Check if there's an active context on the current thread
    ///
    /// \return True if there's a context bound to the current thread
    ///
    ////////////////////////////////////////////////////////////
    static bool IsContextActive();

private :
    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::Display
    ///
    ////////////////////////////////////////////////////////////
    virtual void Display();

    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::SetActive
    ///
    ////////////////////////////////////////////////////////////
    virtual void SetActive(bool Active = true) const;

    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::UseVerticalSync
    ///
    ////////////////////////////////////////////////////////////
    virtual void UseVerticalSync(bool Enabled);

    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::ShowMouseCursor
    ///
    ////////////////////////////////////////////////////////////
    virtual void ShowMouseCursor(bool Show);

    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::SetCursorPosition
    ///
    ////////////////////////////////////////////////////////////
    virtual void SetCursorPosition(unsigned int Left, unsigned int Top);

    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::SetPosition
    ///
    ////////////////////////////////////////////////////////////
    virtual void SetPosition(int Left, int Top);

    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::SetSize
    ///
    ////////////////////////////////////////////////////////////
    virtual void SetSize(unsigned int Width, unsigned int Height);

    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::Show
    ///
    ////////////////////////////////////////////////////////////
    virtual void Show(bool State);

    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::EnableKeyRepeat
    ///
    ////////////////////////////////////////////////////////////
    virtual void EnableKeyRepeat(bool Enabled);

    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::SetIcon
    ///
    ////////////////////////////////////////////////////////////
    virtual void SetIcon(unsigned int Width, unsigned int Height, const Uint8* Pixels);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    EGLContext myGLContext;                    ///< OpenGL context attached to the window
    EGLSurface mySurface;                      ///< OpenGL context attached to the window

protected:  
    ////////////////////////////////////////////////////////////
    // Static member data
    ////////////////////////////////////////////////////////////
    static EGLDisplay     ourDisplay;          ///< Current opened display
    static EGLConfig      ourConfig;           ///< Current config
    static unsigned int   ourWindowsCount;     ///< Number of windows created

    ////////////////////////////////////////////////////////////
    /// Create EGL Surface from a native window handle
    ////////////////////////////////////////////////////////////
    void CreateEGLSurface(WindowHandle Handle);

    ////////////////////////////////////////////////////////////
    /// Open the display (if not already done)
    ///
    /// \param AddWindow : Tell whether or not we must increase the windows count
    ///
    /// \return True if the display is properly opened
    ///
    ////////////////////////////////////////////////////////////
    static bool OpenDisplay(bool AddWindow = true);

    ////////////////////////////////////////////////////////////
    /// Close the display
    ////////////////////////////////////////////////////////////
    static void CloseDisplay();

    ////////////////////////////////////////////////////////////
    /// Define context config
    ////////////////////////////////////////////////////////////
    virtual void ChooseConfig();

    ////////////////////////////////////////////////////////////
    /// Create EGL Context
    ////////////////////////////////////////////////////////////
    virtual bool CreateContext();
};

} // namespace priv

} // namespace sf

#endif // SFML_WINDOWIMPLEGL_HPP
