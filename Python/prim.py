# coding=utf-8
import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
from heapq import heappush
from heapq import heappop


def draw(g, export=False, name='graph'):
    tmp = g.copy()
    for v in tmp.nodes():
        tmp.node[v]['state'] = v

    pos = nx.spring_layout(tmp)

    nx.draw(tmp, pos)
    node_labels = nx.get_node_attributes(tmp, 'state')
    nx.draw_networkx_labels(tmp, pos, labels=node_labels)

    if export:
        plt.savefig(name + '.png')
    else:
        plt.show()
    plt.close()


def prim_mst(g):
    tmp = g.copy()
    push = heappush
    pop = heappop
    nodes = tmp.nodes()

    for n in nodes:
        tmp.node[n]['lambda'] = np.Infinity
        tmp.node[n]['pi'] = None

    tmp.node[0]['lambda'] = 0

    q = []
    visited = []

    for n in nodes:
        push(q, (tmp.node[n]['lambda'], n))

    while q:
        u = pop(q)
        u = u[1]
        visited.append(u)
        for v in tmp.neighbors(u):
            if not v in visited and tmp.node[v]['lambda'] > tmp[u][v]['_weight']:
                q.remove((tmp.node[v]['lambda'], v))
                tmp.node[v]['lambda'] = tmp[u][v]['_weight']
                push(q, (tmp.node[v]['lambda'], v))
                tmp.node[v]['pi'] = u

    h = nx.Graph()
    for u in tmp.nodes():
        h.add_node(u)
        if tmp.node[u]['pi'] is not None:
            h.add_edge(u, tmp.node[u]['pi'])
            h[u][tmp.node[u]['pi']]['_weight'] = tmp[u][tmp.node[u]['pi']]['_weight']
    return h


def read_weighted_adjacency_matrix(path):
    data = np.loadtxt(path)

    rows, cols = np.where(data > 0)

    edges = zip(rows, cols)

    g = nx.Graph(edges)

    for u, v in zip(rows, cols):
        g[u][v]['_weight'] = data[u][v]

    return g


def biggest_edge(g):
    weight = 0
    u = None
    v = None
    for _u, _v in g.edges():
        w = g[_u][_v]['_weight']
        if w > weight:
            weight = weight
            u = _u
            v = _v

    return u, v


def groups(g, n):
    tmp = g.copy()
    for i in range(n - 1):
        u, v = biggest_edge(tmp)
        tmp.remove_edge(u, v)
    return tmp