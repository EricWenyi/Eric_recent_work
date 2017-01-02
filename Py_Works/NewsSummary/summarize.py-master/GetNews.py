
from urllib.request import urlopen
from bs4 import BeautifulSoup


def get_only_text(url):
    page = urlopen(url).read().decode('utf8')
    soup = BeautifulSoup(page)
    text = ' '.join(map(lambda p: p.text, soup.find_all('p')))
    return soup.title.text, text

feed_xml = urlopen('http://feeds.bbci.co.uk/news/rss.xml').read()
feed = BeautifulSoup(feed_xml.decode('utf8'))
to_summarize = list(map(lambda p: p.text, feed.find_all('guid')))

fs = FrequencySummarizer()
for article_url in to_summarize[:1]:
    title, text = get_only_text(article_url)
    with open('new1.txt', 'a') as the_file:
        the_file.write(text)
    print('----------------------------------')
    print(title)
    for s in fs.summarize(text, 2):
        print('*',s)
