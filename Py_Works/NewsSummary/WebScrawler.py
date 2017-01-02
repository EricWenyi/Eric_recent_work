from urllib.request import urlopen
from bs4 import BeautifulSoup

def get_only_text(url):
 """
  return the title and the text of the article
  at the specified url
 """
 page = urlopen(url).read().decode('gb2312')
 soup = BeautifulSoup(page)
 text = ' '.join(map(lambda p: p.text, soup.find_all('p')))
 return soup.title.text, text

feed_xml = urlopen('http://feeds.bbci.co.uk/news/rss.xml').read()
feed = BeautifulSoup(feed_xml.decode('utf8'))
to_summarize = list(map(lambda p: p.text, feed.find_all('guid')))

for i in range(5):
    print(i)
    article_url = to_summarize[i]
    title, text = get_only_text(article_url)
    print(text)
    with open("testing%s.txt" % i, 'a') as myfile1:
        myfile1.write(text)