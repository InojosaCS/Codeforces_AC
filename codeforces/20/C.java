import java.io.*; 
import java.util.*;
 
public class ShortestRoute{
	
	static LinkedList<Pair> graph[] = new LinkedList[100123];
	static Boolean visited[] = new Boolean[100123];
	static Long distance[] = new Long[100123];
	static int parent[] = new int[100123];

	private static void dijkstra(){
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		pq.add(new Pair(0L, 0));
		distance[0] = 0L;

		while(pq.size()  > 0){
			Pair current = pq.poll();
			int node = (int) current.second;
			//System.out.println(node + 1);
			if(visited[node]) continue;
			visited[node] = true;
			for(Pair x : graph[node]){
				int next = (int) x.first;
				Long edge = (Long) x.second;
				//System.out.println(next + 1 + " " + edge + " ||");
				if(distance[node] + edge < distance[next]){
					distance[next] = distance[node] + edge;
					parent[next] = node;
					pq.add(new Pair(distance[next], next));
				}
			}
		}
	}
 
	private static void solve(){
		FastScanner in = new FastScanner();
 
		int n = in.nextInt();
		int m = in.nextInt();
 
		Arrays.fill(visited, false);
		Arrays.fill(distance, 999999999937L);
		Arrays.fill(parent, -1);

		for(int i = 0; i < n; ++i) 
			graph[i] = new LinkedList<Pair>();			
		
		int a,b;
		Long c;

		for (int i=0; i<m; ++i) {
			a = in.nextInt();
			b = in.nextInt();
			c = in.nextLong();
			a--; b--;
			graph[a].add(new Pair(b, c));
			graph[b].add(new Pair(a, c));
		}
 		
		dijkstra(); 

		if(distance[n-1] == 999999999937L){
			System.out.println(-1);
		} else {
			int x = n-1, cnt = 0;
			int ans[] = new int[n+3];

			while(parent[x] != -1){
				ans[cnt] = x;
				x = parent[x];
				cnt++;

			}
			ans[cnt] = 0;
			for(int i = cnt; i > -1; --i)
				System.out.print(ans[i] + 1 + " ");			
			
			System.out.println();
		}
	}
 
	public static void main(String[] args) {
		solve();
	}
 
	// Fast input template by SecondThread https://codeforces.com/profile/SecondThread
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}

class Pair<T1, T2> implements Comparable<Pair<T1, T2>> {
	public T1 first;
	public T2 second;

	public Pair(T1 a, T2 b) {
		this.first = a;
		this.second = b;
	}

	public String toString() {
		return first+" "+second;
	}

	public int hashCode() {
		return Objects.hash(first, second);
	}

	public boolean equals(Object o) {
		if(o instanceof Pair) {
			Pair p = (Pair) o;
			return first.equals(p.first)&&second.equals(p.second);
		}
		return false;
	}

	public int compareTo(Pair<T1, T2> p) {
		int cmp = ((Comparable<T1>) first).compareTo(p.first);
		if(cmp==0) {
			return ((Comparable<T2>) second).compareTo(p.second);
		}
		return cmp;
	}

}

/*
@SuppressWarnings("unchecked")
class Graph { 
    int size;
    LinkedList<Integer> graph[];
 
    public Graph(int size) {
        // Creating graph
        this.size = size;
        graph = new LinkedList[size];
 
        for (int i = 0; i < size; i++) {
            graph[i] = new LinkedList<Integer>();
        }
    }
 
    public void addEdge(int source, int destination, boolean isUndirected){
 
        graph[source].add(destination); //add edge u -> v
 
        if(isUndirected)  //add back edge v -> u (if undirected)
            graph[destination].add(source);
    }
 
    public LinkedList<Integer> getAdj(int index){
        return graph[index];
    }
 
} */