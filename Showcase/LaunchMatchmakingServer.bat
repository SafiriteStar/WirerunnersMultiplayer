:: Simple Batch File To Run Server Executable
:: Launch Server First To Give It Time To Launch
start "" /B "%~dp0MatchmakingServer/MatchmakingServer.exe" UEServerIP=192.168.0.145

cls