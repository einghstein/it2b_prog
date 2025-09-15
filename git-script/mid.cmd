@echo off
if "%~1"=="" (
    echo You must provide a commit message.
    echo Usage: mid "your commit message"
    exit /b 1
)

git add .
git commit -m "%*"
