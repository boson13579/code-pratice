#include <bits/stdc++.h>
#include <string>
using namespace std;

struct team{
	char name[50];
	int point = 0;
	int wins = 0;
	int loses = 0;
	int goals = 0;
	int regoals = 0;
	int tie = 0;
};         

team teams[105];
map<string,int> table;

void judge(string a , string b , int ap , int bp ){
	teams[table[a]].goals += ap;
	teams[table[a]].regoals += bp;
	teams[table[b]].goals += bp;
	teams[table[b]].regoals += ap;
	if(ap>bp){
		teams[table[a]].point += 3;
		teams[table[a]].wins += 1;
		teams[table[b]].loses += 1;
	}
	else if(ap<bp){
		teams[table[b]].point += 3;
		teams[table[b]].wins += 1;
		teams[table[a]].loses += 1;
	}
	else{
		teams[table[a]].point += 1;
		teams[table[b]].point += 1;
		teams[table[a]].tie += 1;
		teams[table[b]].tie += 1;
	}
}

bool cmp(team a,team b){
	if(a.point != b.point)
		return a.point>b.point;
	else if(a.wins != b.wins)
		return a.wins>b.wins;
	else if((a.goals-a.regoals)!=(b.goals-b.regoals))
		return (a.goals-a.regoals) > (b.goals-b.regoals);
	else if(a.goals != b.goals)
		return a.goals > b.goals;
	else if ((a.wins+a.loses+a.tie)!=(b.wins+b.loses+b.tie))
		return (a.wins+a.loses+a.tie)<(b.wins+b.loses+b.tie);
	else
		return strcasecmp(a.name, b.name) < 0;
}

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	int n;cin>>n;
	cin.ignore();
	while(n--){
		string contest_name;
		getline(cin,contest_name);
		cout<<contest_name<<"\n";
		int team_num;
		cin>>team_num;
		//getchar();  
		//team teams[105];  
		for(int i=0 ; i<team_num ; i++){
			gets(teams[i].name);
			teams[i].point = 0;
			teams[i].wins = 0;
			teams[i].loses = 0;
			teams[i].goals = 0;
			teams[i].regoals = 0;
			teams[i].tie = 0;
			table[teams[i].name] = i;
		}
		int contest_times;
		cin>>contest_times;
		cin.ignore();
		for(int i=0 ; i<contest_times ; i++){
			char team1[50] , team2[50];
			int team1point , team2point;
			scanf ("%[^#]#%d@%d#%[^\n]" , team1 ,  & team1point ,  & team2point , team2 );
			getchar();
			judge(team1,team2,team1point,team2point);
		}
		sort(teams,teams+team_num,cmp);
		int now=0;
		for(int i=0 ; i<team_num ; i++){
			cout<<now+1<<") "<<teams[i].name<<" "<<teams[i].point<<"p, "<<teams[i].wins+teams[i].loses+teams[i].tie<<"g ("<<teams[i].wins<<"-"<<teams[i].tie<<"-"<<teams[i].loses<<"), "<<teams[i].goals-teams[i].regoals<<"gd ("<<teams[i].goals<<"-"<<teams[i].regoals<<")\n";
			now++;
		}
		if(bool(n))
			cout<<"\n"; 
	}

	return 0;
}