set filename=%date:~0,4%-%date:~5,2%-%date:~8,2%
git remote -v
git add -A
git status
git commit -m %filename%
git push github computer_702
git push origin computer_702
pause