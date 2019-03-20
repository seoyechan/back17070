#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int nFiled[18][18];
int n;
int nRet = 0;

int dirx[] = { 1, 0, 1 }; // 오른쪽, 아래, 대각
int diry[] = { 0, 1, 1 };

void dfs(int state, int crtx, int crty, int count){ // state 0 : 가로, 1 : 세로, 2 : 대각선

	int nextx = 0;
	int nexty = 0;

	if (crtx == n && crty == n){
		nRet++;
		return;
	}

	switch (state){
	case 0:
		for (int i = 0; i < 3; i++){
			if (i == 1) continue;
			nextx = crtx + dirx[i];
			nexty = crty + diry[i];

			if (nFiled[nexty][nextx]) continue;
			if (i == 2 && (nFiled[nexty][nextx - 1] || nFiled[nexty - 1][nextx])) continue;

			if (nextx > 0 && nextx <= n && nexty > 0 && nexty <= n){
				dfs(i, nextx, nexty, count + 1);
			}
		}
		break;
	case 1:
		for (int i = 1; i < 3; i++){
			nextx = crtx + dirx[i];
			nexty = crty + diry[i];

			if (nFiled[nexty][nextx]) continue;
			if (i == 2 && (nFiled[nexty][nextx - 1] || nFiled[nexty - 1][nextx])) continue;

			if (nextx > 0 && nextx <= n && nexty > 0 && nexty <= n){
				dfs(i, nextx, nexty, count + 1);
			}
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++){
			nextx = crtx + dirx[i];
			nexty = crty + diry[i];

			if (nFiled[nexty][nextx]) continue;
			if (i == 2 && (nFiled[nexty][nextx - 1] || nFiled[nexty - 1][nextx])) continue;

			if (nextx > 0 && nextx <= n && nexty > 0 && nexty <= n){
				dfs(i, nextx, nexty, count + 1);
			}
		}
		break;
	}
}

int main()
{
	freopen("sample_input.txt","r",stdin);

	int t = 1;
	int test_case = 1;

	scanf("%d", &t);

	for (test_case = 1; test_case <= t; ++test_case){

		scanf("%d", &n);

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				scanf("%d", &nFiled[i][j]);
			}
		}

		nRet = 0;
		dfs(0, 2, 1, 0);

		printf("%d\n", nRet);
	}
	return 0;

}