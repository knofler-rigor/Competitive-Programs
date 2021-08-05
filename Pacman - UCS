grid = []
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))
graph = {}
f = []
g = []

for _ in range(c[0]):
    grid.append(list(input()))
for i in range(c[0]):
    for j in range(c[1]):
        if ((grid[i][j]=='-') | (grid[i][j]=='P') | (grid[i][j]=='.')):
            d = []
            try: # Up
                if ((grid[i-1][j]=='-') | (grid[i-1][j]=='P') | (grid[i-1][j]=='.')):
                    d.append(str(int(i-1))+' '+str(int(j)))
            except:
                pass
            try:  # Left
                if ((grid[i][j-1]=='-') | (grid[i][j-1]=='P') | (grid[i][j-1]=='.')):
                    d.append(str(int(i))+' '+str(int(j-1)))

            except:
                pass
            try: # Right
                if ((grid[i][j+1]=='-') | (grid[i][j+1]=='P') | (grid[i][j+1]=='.')):
                    d.append(str(int(i))+' '+str(int(j+1)))
            except:
                pass
            try: # Down
                if ((grid[i+1][j]=='-') | (grid[i+1][j]=='P') | (grid[i+1][j]=='.')):
                    d.append(str(int(i+1))+' '+str(int(j)))
            except:
                pass
            graph[str(int(i))+' '+str(int(j))]=d

def bfs_paths(graph, start, goal):
    f.append(start)
    queue = [(start, [start])]
    while queue:
        (vertex, path) = queue.pop(0)
        for next in [i for i in graph[vertex] if i not in path]:
            if next not in f:
                f.append(next)
            if next == goal:
                return path + [next]
            else:
                queue.append((next, path + [next]))


def shortest_path(graph, start, goal):
    return bfs_paths(graph,  start, goal)

e = shortest_path(graph,str(int(a[0]))+' '+str(int(a[1])), str(int(b[0]))+' '+str(int(b[1])))

print(len(e)-1)
print('\n'.join(e))
