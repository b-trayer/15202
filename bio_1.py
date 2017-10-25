from Bio import Entrez
import networkx as nx
import matplotlib.pyplot as plt

Entrez.email = 'example@g.nsu.ru'

#print ("Enter PubMed ID")

def get_links_id(pmid):
    link_list = []
    links = Entrez.elink(dbfrom="pubmed", db="all", id=pmid, linkname="pubmed_pubmed_refs")
    record = Entrez.read(links)

    records = record[0][u'LinkSetDb'][0][u'Link'] if record[0][u'LinkSetDb'] else []

    for link in records:
        link_list.append(link[u'Id'])

    return link_list

def get_neighbors(pmid):
    link_list = []
    links = Entrez.elink(dbfrom="pubmed", db="all", id=pmid, linkname="pubmed_pubmed_citedin")
    record = Entrez.read(links)

    records = record[0][u'LinkSetDb'][0][u'Link'] if record[0][u'LinkSetDb'] else []

    for link in records:
        link_list.append(link[u'Id'])

    return link_list

#example
pmid = "27041805"
link_list = get_links_id (pmid)
print ('IDs of references ', link_list)
g = nx.MultiGraph()

for link in link_list:
    g.add_edge(pmid, link)

print nx.info(g)
nx.draw(g, with_labels=True)
plt.show()

neighbor_list = get_neighbors (pmid)
print ('Cited by this IDs', neighbor_list)
gg = nx.MultiGraph()

for link in neighbor_list:
    gg.add_edge(pmid, link)

print nx.info(gg)
nx.draw(gg, with_labels=True)
plt.show()
