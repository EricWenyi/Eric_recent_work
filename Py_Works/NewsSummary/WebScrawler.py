from urllib.request import urlopen
from bs4 import BeautifulSoup
import NewsSummary2

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

for i in range(41,50):

    print(i)
    article_url = to_summarize[i]
    title, text = get_only_text(article_url)
    text = text.replace("Share this with Email Facebook Messenger "
                       "Messenger Twitter Pinterest WhatsApp LinkedIn Copy this link ", "")
    with open("News_%s.txt" % i, 'a') as myfile1:
        myfile1.write(text)
    with open("Title_%s.txt" % i, 'a') as myfile2:
        myfile2.write(title)

    string = text.replace('\n','')
    summary = NewsSummary2.Summarize(string, 2)
    with open("Summary_%s.txt" % i, 'a') as myfile3:
        for sents in summary:
            myfile3.write(sents + '\n')
