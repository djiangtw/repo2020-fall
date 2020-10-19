# repo2020-fall
該複習一下題目了，雜記，寫給自己看的。
有空打電動不如打leetcode，有時間就寫點，讓腦袋動一動。

# Tree
- 基本建立、刪除寫在#l-100裡
- 常用tests放在#d-1
- 下面兩對fucntions有什麼不一樣呢? 有的，其中一種方式會丟掉資料，這是常見的傳值和傳指標誤區，詳細說明和解答請參考這個連結：https://chenhh.gitbooks.io/parallel_processing/content/cython/memory_leak.html
```
  struct TreeNode*  newNode(int v)
  void newNode1(struct TreeNode* p, int v)
  struct TreeNode* newTree(int nums[], int numSize)
  void newTree1(struct TreeNode* p, int nums[], int numSize)
```

# Singly Linked List
基本建立、刪除寫在#l-2裡

# 程序猿修練之道
- care about your craft.
- thnk! about your work.
- provide options, don't make lame excuses.
- don't live with broken windows.
- be a catalyst for change.
- remember the big picture.
- make quality a requirements issue. 讓你的客戶一起定義項目真正的需求!
- invest regularly in your knowldege portfolio.
- critically analyze what you read and hear.
- it's both what you say and the way you say it.
- don't repeat yourself.
- make it easy to reuse.
- eliminate effects between unrelated things.
- there are no final decisions.
- use tracer bullets to find the target. 隨時要檢查方向對不對!
- prototype to learn. 建模來見識一下可能遇到的錯誤，吸取經驗。Model建置是要準還是要快? 這是一個好問題!
- program close to the problem domain. 
- estimate to avoid surprises. 除了估計，也要隨時檢查。
- interate the schedule iwth the code.
- keep knowledge in plain text.
- use the power of command shells
- use a single editor well
- always use source code control
- fix the problem, not the blame. "光"抱怨沒有用，問題還是要動手去解決!
- don't panic when debugging. 輕鬆愉快的氣氛有助於除錯! 請考慮雇用加油打氣工程師(誤).
- select isn't broken. Bug無所不在，多從各個面向的應用中去找，找到就是收穫.
- don't assume it, prove it. 科學家精神，大膽假設，小心求證，用科學的方法去解釋。
- learn a text manupulation language.
- write code that write code. 代碼生成器! 好用!
- you can't write perfect software. 只能儘量努力，起碼品質要堅若磐石
- desogm wotj cpmtracts
- crash early
- use assertions to prevent the impossible
- use exceptions for exceptoinal problems
- finish what you start
- minimuze coupling between modules.
- configure, don't integrate. 能配置就不要集成。(用選項去設定，不要改代碼!!)
- put abstractions in code, details in metadata. 細節放在參考文件，愈詳細愈好!
- analyze workflow to improve concurrency.
- design using services.
- always design for concurrency.
- separate views from models.
- use blackboards to coordinate workflow. 很多工具可以用，好好用!
- don't program by coincidence.
- estimate the order of your algorithms. 不是只要沒問題的執行，還要執行的有效率!
- test your estimates.
- refactor early, refactor often.
- design to test
- test your software, or your users will.
- don't use wizard code you don't understand.
- don't gather requirements, dig for them.
- work with a user to think like a user.
- abstraction live longer than details.
- use a project glossary.
- don't thnk outside the box, find the box.
- start when you're ready.
- some things are better done than described.
- don't be a slave to formal methods.
- costly tools don't produce better designs.
- organize teams around functionality.
- don't use manual procedures.
- test early, test often, test automatically. 不要浪費時間!有空常驗證!自動化驗證!
- coding ain't done till all the tests run.
- use saboteurs to test your testing. 抓罕見問題、確認軟體的健全!
- test state coverage, not code coverage.
- find bugs once.
- english is just a programming language.
- build documentation in, don't bolt it on. 做好習慣，根據文件來更新代碼!免得更新了代碼卻忘了文件。
- gently exceed your users' expectations.
- sign your work. 對自己的代碼負責

## Wisdom
```
What do you want them to learn?
What is their interest in what you've got to say
How sophisticated are they?
How much detail do they want?
Whom do you want to own the information?
How can you motivate them to listen to you?
```

## Prototyping
- Arch
- Features
- Structures
- 3rd party tools
- performance
- user interface if needed

## hard problems
- any easier solution?
- are we solving the correct problem?
- why is it a problem?
- what make it a hard problem?
- is it the only way to solve the problem?
- should we need to solve it?

## Testing
- unit test
- integration test
- verification and validation
- out of resource? error? recovery?
- performance test
- functional test
- how to test?

