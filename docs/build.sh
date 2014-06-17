pandoc -f markdown -t html zenozeng.md -s > tmp.html
echo "<style>body{font-size: 16pt}</style>" >> tmp.html
wkhtmltopdf -T 25mm -R 25mm -B 25mm -L 25mm tmp.html zenozeng.pdf
rm tmp.html
