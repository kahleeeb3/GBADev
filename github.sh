echo "Push Comment:"
read x
git add --all;
git commit -a -m "${x}";
git push;