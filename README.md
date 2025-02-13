<header>
  <h1><b># 🐍 Snake Game (C++)</b></h1>
  <p>A console-based Snake Game built in C++ using object-oriented programming (OOP) and linked lists. The game features smooth controls, difficulty selection, colored UI, and a flicker-free console experience.</p>
</header>

<hr>
<body>
  <h2><b>## 🪪 Student IDs </b></h2>
  <ol>
    <li><b>Dhruvam Panchal (202401415)</b></li>
    <br>
    <li><b>Shubh Patel (202401478)</b></li>
    <br>
    <li><b>Dwij Patel (202401418)</b></li>
    <br>
    <li><b>Yashraj Solanki (202401481)</b></li>
  </ol>
  <h2><b>## 📜 Table of Contents</b></h2>
  <ul>
    <li>Features</li>
    <li>Installation</li>
    <li>Usage</li>
    <li>Controls</li>
    <li>Difficulty Levels</li>
    <li>Data Structure Analysis</li>
    <li>Code Structure</li>
    <li>Future Improvements</li>
    <li>License</li>
    <li>Contributing</li>
    <li>Contact</li>
    <li>Limitations</li>
  </ul>
<h2><b>## ✨ Features</b></h2>
  <ul>
    <li><b>Grid-based gameplay</b></li>
    <br>
    <li><b>Snake starts with 3 cells and grows when eating food</b></li>
    <br>
    <li><b>Difficulty selection(Easy, Medium, Hard)</b></li>
    <br>
    <li><b>Colored UI(Walls, Snake, and Food)</b></li>
    <br>
    <li><b>No screen flickering in VS Code & terminals</b></li>
    <br>
    <li><b>Collision detection (walls & self)</b></li>
    <br>
    <li><b>Score tracking and restart option</b></li>
    <br>
    <li><b>High score maintenance across all the games played until the exit key 'X' pressed</b></li>
  </ul>
<h2><b>## 🛠 Installation</b></h2>
  <ol type="I">
    <li><b>Clone the Repository</b></li>
    <div>$ git clone https://github.com/yourusername/snake-game-cpp.git</div>
    <div>$ cd snake-game-cpp</div>
    <br>
    <li><b>Compile the Code (Using g++)</b></li>
    <div>$ g++ snake_game.cpp -o snake_game.exe</div>
    <br>
    <li><b>Run the Game</b></li>
    <div>$ snake_game</div>
  </ol>
<h2><b>## 🎮 Usage</b></h2>
  <div>After running the game, follow these steps:</div>
  <ol>
    <br>
    <li>Read the game instructions displayed on the screen.</li>
    <li>Select your difficulty level:</li>
    <div>-> Press 1 for Easy</div>
    <div>-> Press 2 for Medium</div>
    <div>-> Press 3 for Hard</div>
    <li>Control the snake using W/A/S/D keys.</li>
    <li>Eat F (food) to grow and increase your score.</li>
    <li>Avoid colliding with walls (#) and yourself.</li>
    <li>Press R to restart or X to exit after Game Over.</li>
  </ol>
<h2>## 🎮 Controls</h2>
<table>
    <thead>
      <tr>
        <th scope="col" style="border: 1px solid black;">Key</th>
        <th scope="col" style="border: 1px solid black;">Action</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <th scope="row" style="border: 1px solid black;">W</th>
        <td style="border: 1px solid black;">Move Up</td>
      </tr>
      <tr>
        <th scope="row" style="border: 1px solid black;">A</th>
        <td style="border: 1px solid black;">Move Left</td>
      </tr>
      <tr>
        <th scope="row" style="border: 1px solid black;">S</th>
        <td style="border: 1px solid black;">Move Down</td>
      </tr>
      <tr>
          <th scope="row" style="border: 1px solid black;">D</th>
          <td style="border: 1px solid black;">Move Right</td>
      </tr>
      <tr>
        <th scope="row" style="border: 1px solid black;">X</th>
        <td style="border: 1px solid black;">Exit the Game</td>
      </tr>
      <tr>
        <th scope="row" style="border: 1px solid black;">R</th>
        <td style="border: 1px solid black;">Restart the Game and Select Difficulty Again</td>
      </tr>
   </tbody>
</table>
<h2>## 🔥 Difficulty Levels</h2>
<table>
  <thead>
    <tr>
      <th scope="col" style="border: 1px solid black;">Level</th>
      <th scope="col" style="border: 1px solid black;">Speed (ms delay)</th>
      <th scope="col" style="border: 1px solid black;">Difficulty</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th scope="row" style="border: 1px solid black;">1 - Easy</th>
      <td style="border: 1px solid black;">150 ms</td>
      <td style="border: 1px solid black;">🟢 Best for beginners</td>
    </tr>
    <tr>
      <th scope="row" style="border: 1px solid black;">2 - Medium</th>
      <td style="border: 1px solid black;">100 ms</td>
      <td style="border: 1px solid black;">🟡 Balanced challenge</td>
    </tr>
    <tr>
      <th scope="row" style="border: 1px solid black;">3 - Hard</th>
      <td style="border: 1px solid black;">50 ms</td>
      <td style="border: 1px solid black;">🔴 Fast-paced gameplay</td>
    </tr>
  </tbody>
</table>
<h2>## 📊 Data Structures Analysis</h2>
<div>
  <h3><b>1. What Data Structures Were Used?</b></h3>
  <ul>
    <li><b>Linked List (<code>std::list&lt;std::pair&lt;int, int&gt;&gt;</code>)</b>
      <ul>
        <li>Stores the snake’s body.</li>
        <li>Allows efficient insertion & deletion (O(1) time complexity).</li>
        <li>Eliminates the need for resizing like arrays.</li>
      </ul>
    </li>
    <li><b>2D Grid Representation (<code>std::pair&lt;int, int&gt;</code>)</b>
      <ul>
        <li>Tracks the snake's head, body, and food position.</li>
      </ul>
    </li>
  </ul>
</div>

<div>
  <h3><b>2. Why Was a Linked List Chosen?</b></h3>
  <ul>
    <li><b>Efficient Growth:</b> The snake dynamically expands without resizing overhead.</li>
    <li><b>Constant-time operations:</b> Adding a new head and removing the tail is O(1).</li>
    <li><b>Avoids shifting elements:</b> Unlike an array where moving elements would be O(n).</li>
  </ul>
</div>
<div>
<h3><b>3. Object-Oriented Structure</b></h3>
  <table>
    <thead>
     <tr>
      <th scope="col" style="border: 1px solid black;">Class</th>
      <th scope="col" style="border: 1px solid black;">Responsibility</th>
     </tr>
    </thead>
    <tbody>
     <tr>
      <th scope="row" style="border: 1px solid black;">SnakeGame</th>
      <td style="border: 1px solid black;">Handles game logic, rendering, movement, collision detection.</td>
     </tr>
     <tr>
      <th scope="row" style="border: 1px solid black;">list(pair(int, int)) snake</th>
      <td style="border: 1px solid black;">Stores the snake’s body using a linked list.</td>
     </tr>
     <tr>
      <th scope="row" style="border: 1px solid black;">pair(int, int) food</th>
      <td style="border: 1px solid black;">Stores the food's position in the grid.</td>
     </tr>
    </tbody>
  </table>
  </div>
<h2>## 📁 Code Structure</h2>
  <div>📂 Snake-Game-Cpp/</div>
  <br>
  <div>│── 📄 README.md           # Project documentation</div>
  <br>
  <div>│── 📄 snake_game.cpp      # Main game source code</div>
  <br>
  <div>│── 📄 LICENSE             # License details</div>
<h2>## 🚀 Future Improvements</h2>
<div>🔹 Obstacles Mode – Add randomly generated walls.</div>
  <br>
<div>🔹 Power-Ups – Introduce special food that grants speed boosts or extra points.</div>
  <br>
<div>🔹 Multiplayer Mode – Allow two players to control different snakes.</div>
<h2>## 📜 License </h2>
<div>This project is open-source and available under the MIT License.
Feel free to modify and use it for educational purposes! 🎉 </div>
<h2>## 📢 Contributing </h2>
<div>Feel free to contribute! To do so:</div>
<br>
<div>1. Fork this repository.</div>
<div>2. Create a new branch (feature-name).</div>
<div>3. Commit your changes (git commit -m "Added new feature").</div>
<div>4. Push to GitHub and create a Pull Request.</div>
<h2>## 📞 Contact </h2>
<div>💡 Found a bug or have suggestions? Open an issue or reach out:</div>
<br>
<div>-> 📧 Email : panchaldhruvam19@gmail.com</div>
<div>-> GitHub : <a href= "https://github.com/Dhruvam1111">github.com/Dhruvam1111</a></div>
<br>
<div>-> 📧 Email : dwijpatel125@gmail.com</div>
<div>-> GitHub : <a href= "https://github.com/Dwijpatel125">github.com/Dwijpatel125</a></div>
<br>
<div>-> 📧 Email : solankiyashrajsinhn@gmail.com </div>
<div>-> GitHub : <a href= "https://github.com/Yashrajsinh06">github.com/Yashrajsinh06</a></div>
<br>
<div>-> 📧 Email : shubhpatel2005@gmail.com</div>
<h2>## ⚠️ Limitations</h2>
<p><b>NOTE :</b> This is an OS dependent game. <b>It runs only on windows</b> as the source code file contains external terminal related library <b>(windows.h)</b>, which is available <b>only on windows</b>. It is used for navigation purposes inside the game.
</body>
<hr>
<footer>
<br>
<div>🎉 Thanks for checking out this project! Hope you enjoy playing! 🚀 </div>
</footer>
