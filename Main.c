//little edit
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define INF 99999
typedef struct node{
    int index;
    char *to;
    int price;
    float time;
    struct node *next;
}cities;
struct graph
{
    int noOfCities;
    cities **lists;
};
char CITY[][20]={"Delhi", "Mumbai", "Hyderabad", "Chennai",
                    "Bengaluru", "Bhopal", "Vijayawada"};
char *getCity(int index){
    return CITY[index];
}
int getIndex(char *c){
    int i=0;
    while(1){
        if(0==strcmp(c,CITY[i]))
            return i;
        i++;
    }
}
cities *createCity(int i, char *d, int p, float t)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->index=i;
    new->to = d;
    new->price=p;
    new->time=t;
    new->next = NULL;
    return new;
}
struct graph *createGraph(int noOfCities)
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->noOfCities = noOfCities;
    g->lists = (struct node **)malloc(sizeof(struct node *) * noOfCities);
    while (noOfCities > 0)
    {
        g->lists[--noOfCities] = NULL;
    }
    return g;
}
void addEdge(struct graph *g, char *s, char *d, int p, float t)
{
    int fromIndex=getIndex(s),toIndex=getIndex(d);
    printf("\n\n%d\n\n\n",toIndex);
    struct node *new = createCity(toIndex,d,p,t);
    new->next = g->lists[fromIndex];
    g->lists[fromIndex] = new;
}
void print(struct graph *g)
{
    for (int v = 0; v < g->noOfCities; v++)
    {
        cities *t = g->lists[v];
        while (t)
        {
            printf("\n From %s ", getCity(v));
            printf("To %s price %d %d hrs %d min\n", getCity(t->index),t->price,(int)t->time,1+(int)((t->time-(int)t->time)*60));
            //printf("To %s price %d time %f\n", t->to,t->price,t->time);
            t = t->next;
        }
    }
}
void currentFlights(struct graph *g, char *city){
    cities *t = g->lists[getIndex(city)];
    printf("Available flights from %s : ",city);
    while(t){
        printf("%s ",getCity(t->index));
        t=t->next;
    } 
}
void dijkstrallSourceDestinationPrice(struct graph *g,int n, char* source, char* destination) {
    //this function is dijkstra using List Source Destination
    int i,j,max=0;
    int s=getIndex(source), d=getIndex(destination);
    int *visited=(int *)calloc(n,sizeof(int));
    int *price=(int *)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        price[i]=INF;
    } 
    price[s]=0;
    for(i=0;i<n;i++){
        int uu=INF,u=-1;
        for(j=0;j<n;j++){
            if(uu>=price[j]&&visited[j]==0){
                uu=price[j];
                u=j;
            }
        }
        visited[u]=1;
        struct node *t = g->lists[u];
        while(t){
            max+=t->price;
            if(visited[t->index]==0){
                if(price[t->index]>price[u]+t->price){
                    price[t->index]=price[u]+t->price;
                }
            }
            t=t->next;
        }
    }
    if(price[d]>max){
        printf("-1\n");
    }else{
        printf("%d\n",price[d]);
    }
}
void dijkstrallSourceDestinationTime(struct graph *g,int n, char* source, char* destination) {
    //this function is dijkstra using List Source Destination
    int i,j,max=0;
    int s=getIndex(source), d=getIndex(destination);
    int *visited=(int *)calloc(n,sizeof(int));
    float *time=(float *)calloc(n,sizeof(float));
    for(i=0;i<n;i++){
        time[i]=INF;
    } 
    time[s]=0;
    for(i=0;i<n;i++){
        int u=-1;
        float uu=INF;
        for(j=0;j<n;j++){
            if(uu>=time[j]&&visited[j]==0){
                uu=time[j];
                u=j;
            }
        }
        visited[u]=1;
        struct node *t = g->lists[u];
        while(t){
            max+=t->price;
            if(visited[t->index]==0){
                if(time[t->index]>time[u]+t->time){
                    time[t->index]=time[u]+t->time;
                }
            }
            t=t->next;
        }
    }
    if(time[d]>max){
        printf("-1\n");
    }else{
        printf("%d hrs %d min\n",(int)time[d],1+(int)((time[d]-(int)time[d])*60));
    }
}
void main(){
    struct graph* g=createGraph(7);
    int n,price;
    char source[20],destination[20];
    float time;
    FILE *fp=fopen("dataList.txt","r");
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        fscanf(fp,"%s %s %d %f",&source, &destination, &price, &time);
        addEdge(g,source, destination, price, time);
    }
    print(g);
    currentFlights(g, "Bengaluru");
    dijkstrallSourceDestinationPrice(g,7,"Delhi", "Hyderabad");
    dijkstrallSourceDestinationTime(g,7,"Delhi", "Hyderabad");
}