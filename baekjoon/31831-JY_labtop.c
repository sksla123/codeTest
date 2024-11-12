// 문제
// 상원이는 과민성 대장 증후군을 앓고 있다. 과민성 대장 증후군의 원인은 스트레스!

// 상원이의 
// $N$일 동안의 스트레스 변화량 
// $A_1,\cdots ,A_N$이 주어진다. 
// $A_i\ge 0$ 이면 
// $i$번째 날에 
// $A_i$ 만큼 스트레스가 쌓이고, 
// $A_i<0$ 이면 
// $i$번째 날에 
// $-A_i$ 만큼 스트레스가 해소된다. 단, 변화를 관찰하기 시작한 시점의 스트레스 양은 
// $0$이며, 누적된 스트레스 양보다 해소하는 스트레스 양이 더 많을 경우 스트레스는 
// $0$이 될 때까지만 감소한다.

// 상원이는 스트레스가 
// $M$ 이상 쌓인 날에 복통을 겪게 될 때, 상원이가 며칠 동안 복통에 시달리게 되는지 알아보자.

// 입력
// 첫째 줄에 스트레스 변화를 관찰한 일수 
// $N$과 복통을 겪게 되는 스트레스의 양 
// $M$이 주어진다.

// 둘째 줄에 스트레스 변화량 
// $A_1,A_2,\cdots ,A_N$이 공백으로 구분되어 주어진다.

// 출력
// 상원이가 복통을 겪게 되는 일수를 출력한다.

// 제한
//  
// $1\leq N\leq 10^5$ 
//  
// $1\leq M\leq 10^9$ 
//  
// $-10^4\leq A_i\leq 10^4(1\le i\le N)$ 
// 입력으로 주어지는 수는 모두 정수이다.

nt main() {
    long long int n, m, added_stress, recent_stress = 0;
    long long int stresses[10101010101010];

    scanf("%lld %lld", &n, &m);
    for(long long int i = 0; i< n; i++) {
        scanf("%lld", &added_stress);
        recent_stress += added_stress;
        
        if (recent_stress < 0) recent_stress = 0;

        stresses[i] = recent_stress;
    }



    return 0;
}