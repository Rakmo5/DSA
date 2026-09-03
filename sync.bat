@echo off
echo ============================================
echo   🚀 SYNCHRONIZING DSA WORKSPACE PROGRESS 🚀
echo ============================================
echo.
echo [1/3] Re-calculating stats from Excel...
python "%~dp0generate_readme.py"
if errorlevel 1 (
    echo.
    echo ❌ ERROR: Failed to generate README!
    pause
    exit /b
)

echo.
echo [2/3] Staging all files...
git add .

echo.
echo [3/3] Committing changes...
git commit -m "Update progress dashboard and C++ code"

echo.
echo Pushing changes to personal GitHub...
git push origin main
if errorlevel 1 (
    echo.
    echo ❌ ERROR: Failed to push to GitHub! Check your network or credentials.
    pause
    exit /b
)

echo.
echo ============================================
echo   🎉 SUCCESS: Workspace and GitHub are in Sync! 🎉
echo ============================================
pause
