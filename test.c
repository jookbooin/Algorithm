 
 
 731         for (;;) {
 732                 set_current_state(TASK_INTERRUPTIBLE);
 733                 if (list_empty(&kthread_create_list))      // 아무것도 없다면 
 734                         schedule();                        // 자러 간다.
 735                 __set_current_state(TASK_RUNNING);         // 존재한다면 → Running 상태
 736 
 737                 spin_lock(&kthread_create_lock);           // 락을 건다.

 738                 while (!list_empty(&kthread_create_list)) {
 739                         struct kthread_create_info *create;
 740 
 741                         create = list_entry(kthread_create_list.next,
 742                                             struct kthread_create_info, list);  // linkedList 의 next로 kthread_create_info 형태로
                                                                                     // 자료를 꺼내온다.

 743                         list_del_init(&create->list);
 744                         spin_unlock(&kthread_create_lock);
 745 
 746                         create_kthread(create);                                // 자료구조에서 가져온 정보로 커널 스레드 생성
 747 
 748                         spin_lock(&kthread_create_lock);
 749                 }
 750                 spin_unlock(&kthread_create_lock);
 751         }
