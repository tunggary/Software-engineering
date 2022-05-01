# 2.Actor Descriptions

| actor                      | descriptions                                                                                               |
| :------------------------- | :--------------------------------------------------------------------------------------------------------- |
| 사용자                     | 의류 쇼핑 사이트 사용권한이 없는 자. 회원가입을 통해 의류 쇼핑 사이트의 사용권한을 얻을 수 있다.           |
| 회원                       | 의류 쇼핑 사이트 사용권한이 있는 자. 상품을 판매,구매 할 수 있는 사용자                                    |
| 판매자                     | 상품을 판매 혹은 판매한 상품을 관리하려는 회원                                                             |
| 구매자                     | 상품을 구매 혹은 구매한 상품을 관리하려는 회원                                                             |
| 결제 시스템                | 상품 구매 시 결제를 담당하는 외부시스템.                                                                   |
| 택배사                     | 환불 상품을 수거하는 외부 시스템. 환불을 신청하는 경우 택배사 시스템에 자동으로 물품 수거 신청이 요청된다. |
| 이메일 시스템              | 이메일 발송을 요청했을때 이를 담당하는 외부시스템                                                          |
| 매월말일 event             | 모든 회원들에게 현재까지의 모든 판매 및 구매 통계 정보를 이메일로 공지하기 위해 매월 말일에 발생하는 event |
| 구매 후 6개월이 지남 event | 상품을 구매한 날로부터 6개월이 지났을 때 발생하는 event                                                    |