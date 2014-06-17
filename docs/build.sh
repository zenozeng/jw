pandoc -f markdown -t html zenozeng.md -s > zenozeng.html
echo "<style>body{font-size: 12pt; width: 100%; font-size: 'WenQuanYi Micro Hei'; padding: 4em}</style>" >> zenozeng.html
# wkhtmltopdf -T 25mm -R 25mm -B 25mm -L 25mm --page-size letter zenozeng.html zenozeng.pdf
