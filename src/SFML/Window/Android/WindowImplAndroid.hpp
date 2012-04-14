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

#ifndef SFML_WINDOWIMPLANDROID_HPP
#define SFML_WINDOWIMPLANDROID_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowImpl.hpp>
#include <SFML/Window/EGL/WindowImplEGL.hpp>
#include <string>


namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
/// WindowImplAndroid is the Android implementation of WindowImpl
////////////////////////////////////////////////////////////
class WindowImplAndroid : public WindowImplEGL
{
public :

    ////////////////////////////////////////////////////////////
    /// Default constructor
    /// (creates a dummy window to provide a valid OpenGL context)
    ///
    ////////////////////////////////////////////////////////////
    WindowImplAndroid();

    ////////////////////////////////////////////////////////////
    /// Construct the window implementation from an existing control
    ///
    /// \param Handle : Platform-specific handle of the control
    /// \param Params : Creation parameters
    ///
    ////////////////////////////////////////////////////////////
    WindowImplAndroid(WindowHandle Handle, WindowSettings& Params);

    ////////////////////////////////////////////////////////////
    /// Create the window implementation
    ///
    /// \param Mode :        Video mode to use
    /// \param Title :       Title of the window
    /// \param WindowStyle : Window style
    /// \param Params :      Creation parameters
    ///
    ////////////////////////////////////////////////////////////
    WindowImplAndroid(VideoMode Mode, const std::string& Title, unsigned long WindowStyle, WindowSettings& Params);

    ////////////////////////////////////////////////////////////
    /// Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~WindowImplAndroid();

    ////////////////////////////////////////////////////////////
    /// Check if there's an active context on the current thread
    ///
    /// \return True if there's a context bound to the current thread
    ///
    ////////////////////////////////////////////////////////////
    static bool IsContextActive();

private :

    ////////////////////////////////////////////////////////////
    /// /see WindowImpl::ProcessEvents
    ///
    ////////////////////////////////////////////////////////////
    virtual void ProcessEvents();

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
    WindowHandle myHandle;                         ///< ANativeWindow handle
};

} // namespace priv

} // namespace sf

#endif // SFML_WINDOWIMPLANDROID_HPP
