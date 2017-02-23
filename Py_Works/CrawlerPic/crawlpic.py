import urllib2
import urllib
import re

url="http://www.bbc.com/news/world-us-canada-38526570"
response=urllib2.urlopen(url)
html=response.read()

reg=r'src="(http://ichef-1.*?.jpg)"'
imgre=re.compile(reg)
imlist=re.findall(reg,html)

cnt=1
for imurl in imlist:
    print cnt
    print imurl
    urllib.urlretrieve(imurl,"%s.jpg"%cnt);
    cnt+=1
