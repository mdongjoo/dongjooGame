<img src="https://capsule-render.vercel.app/api?type=waving&color=BDBDC8&height=150&section=header" />

# dongjoo game 


## 📁 콘솔게임 소개
2020 년도 visual studio c/c++을 이용해 간단한 콘솔 미니게임을 구현했습니다


##  제작 배경
코딩 로직구현에 관심이 많았기에 무언가 간단하게라도 로직을 활용해 미니게임 프로젝트를 만들어보고자했다
w,a,s,d 와 space bar 를 이용한 미로찾기게임! 

## 게임 화면 

## 메인화면 
![동주 메인화면](https://github.com/user-attachments/assets/5fce5c7b-d425-4aad-ad97-0558fc56ebd5)
![게임정보 커서](https://github.com/user-attachments/assets/2c3af43f-52b4-431b-9ed4-f63063b943be)

- 게임의 시작인 메인화면의 로고를 이름을 본따 dongjoo 를 만들었습니다.
- 게임시작, 게임 정보 , 종료를 space bar로 선택할 수 있고
- 해당 > 의 위치에 따라 선택이 달라질 수 있도록 로직을 구현했습니다.
- > 의 위치는 3칸만 이동이 가능하도록 구현했습니다.  

##  게임방법
![게임방법](https://github.com/user-attachments/assets/5f6d44f0-2df8-45e0-942e-c3b4fe14091a)

- 키보드의 w,a,s,d,space bar 를 누르면 위치의 변화나 선택이 가능하도록 구현했습니다
- 게임 방법에는 개발자의 이름과 메인화면으로 이동이 가능하다는 문구를 넣어두어 좀 더 쉽게 이해가 가능하도록 만들었습니다.

## 맵 선택
![맵 선택](https://github.com/user-attachments/assets/88958529-0b49-4606-951f-4d8fdbe63c90)

- 게임시작을 선택하면 [맵 선택] 화면으로 이동되고
- 난이도는 쉬움 , 어려움으로 제작했습니다 추가적으로 난이도에 따른 맵은 더 만들수있게 cpp 함수를 나누어 설계했습니다
- 쉬움을 눌렀다고 가정하고 게임을 진행해보겠습니다.

## 쉬움 난이도 맵 화면
![쉬움 맵1](https://github.com/user-attachments/assets/769a54e7-4a35-4509-aa1a-b8311c543606)

- 아래 하단에는 @ (유저)의 위치가 x , y 좌표로 보여집니다
- 열쇠의 개수도 확인이 가능하고 열쇠의 모양은 * 입니다.
- 하얀 벽에는 갈 수 없고 빨간 벽에 닿으면 game이 종료됩니다.
- *을 먹으면 열쇠 개수가 늘고 열쇠가 있어야만 + 의 문이 열립니다
- +의 문이 열리면 열쇠의 개수가 적어집니다.
- 0의 차원문으로 들어가면 게임을 클리어할 수 있습니다.
- 
![게임오버](https://github.com/user-attachments/assets/7569d0d7-afcf-4fff-afb7-faa4b9186573)
![열쇠먹기](https://github.com/user-attachments/assets/a356e7b1-435c-4652-83da-c39777a23278)
![문개방](https://github.com/user-attachments/assets/eb98db4a-9899-4245-9ab5-c85ff31152d5)
![게임클리어](https://github.com/user-attachments/assets/d99d90bb-02e3-4542-b199-3acb3fca3a8f)

## 🔗제작 인원
| 팀원  | 문동주 |

## 결과
아주 잘 작동했고 , 이 게임을 제작하면서 코딩/언어에 많은 관심을 더더욱 가질 수 있게된것같습니다. 
