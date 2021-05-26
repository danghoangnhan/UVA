
import java.util.*;
import java.util.Vector;
import java.util.List;

 class node
{
    node (int a,int cost){
        to =a;
        this.cost=cost;
    }
    public int to;
    public int cost;
}
 class uva11374
{
    public static final int N = 501;
    public static final int INF = 10000000;

    public static ArrayList<node>[] edge = new ArrayList<node>[N];
    public static int[] dis_s = new int[N];
    public static int[] dis_e = new int[N];
    public static int[] parent_s = new int[N];
    public static int[] parent_e = new int[N];

    public static void Dijkstra(int n, int s, int[] dis, int[] parent)
    {
        boolean[] vis = new boolean[N];

        for(int i = 1; i <= n; i++)
        {
            dis[i] = INF;
            vis[i] = false;
        }
        dis[s] = 0;
        parent[s] = s;

        int u;
        int min;
        for (int t = 1; t <= n; t++)
        {
            u = 0;
            min = INF;

            for (int i = 1; i <= n; i++)
            {
                if (!vis[i] && dis[i] < min)
                {
                    min = dis[i];
                    u = i;
                }
            }

            vis[u] = true;

            for (int i = 0; i < edge[u].size(); i++)
            {
                int v = edge[u].get(i).to;
                int w = edge[u].get(i).cost;

                if (!vis[v] && dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    parent[v] = u;
                }
            }

        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n,m,k,s,e,x,y,cost;
        boolean flag = false;

        while (in.hasNextInt())
        {
            for (int i = 1; i <= n; i++) edge[i].clear();

            m = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));

            while ((m--) != 0)
            {
                x = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
                y = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
                cost = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
                edge[x].add(new node(y, cost));
                edge[y].add(new node(x, cost));
            }

            Dijkstra(n, s, dis_s, parent_s);
            Dijkstra(n, e, dis_e, parent_e);

            k = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));

            int distance = dis_s[e];
            int ts = 0;
            int te = 0;

            while ((k--) != 0)
            {
                x = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
                y = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
                cost = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
                if (dis_s[x] + cost + dis_e[y] < distance)
                {
                    distance = dis_s[x] + cost + dis_e[y];
                    ts = x;
                    te = y;
                }
                if (dis_s[y] + cost + dis_e[x] < distance)
                {
                    distance = dis_s[y] + cost + dis_e[x];
                    ts = y;
                    te = x;
                }
            }

            int station = ts;

            if (flag)
            {
                System.out.print("\n");
            }
            flag = true;

            if (ts == 0 && te == 0)
            {
                while (s != e)
                {11516-int.print("\n");
            }
            else
            {
                int[] buffer = new int[N];
                int index = 0;

                while (ts != s)
                {
                    buffer[index++] = ts;
                    ts = parent_s[ts];
                }
                buffer[index++] = s;

                for (int i = index - 1; i >= 0; i--)
                {
                    System.out.print(buffer[i]);
                    System.out.print(" ");
                }

                while (te != e)
                {
                    System.out.print(te);
                    System.out.print(" ");
                    te = parent_e[te];
                }
                System.out.print(e);
                System.out.print("\n");
            }

            if (station == 0)
            {
                System.out.print("Ticket Not Used\n");
            }
        }
    }


