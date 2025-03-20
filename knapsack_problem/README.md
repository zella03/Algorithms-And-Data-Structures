<h1>Knapsack problem</h1>
<p>
  Solution to the Knapsack Problem, specifically the 0/1 Knapsack variation, using a brute-force approach (checking all possible combinations).<br><br>
  Tasks:
  <ul>
    <li>Reading package information (payment, weight) and knapsack capacity.</li>
    <li>Generating all possible combinations of packages using binary representations.</li>
    <li>Calculating the total payment and weight for each combination.</li>
    <li>Finding the combination with the maximum payment that fits within the knapsack's weight limit.</li>
    <li>Printing the maximum payment.</li>
  </ul>
  <br><br>
</p>
<h3>Example</h3>
<p>
  <strong>Input: </strong>3 60 100 120 10 20 30 50<br>
  <i>n=3, payment=[60,100,120], sizes=[10,20,30], maxSize=50</i>
  <br><br>
  <strong>Output: </strong>220
  <br><br>
</p>
<h3>Explanation</h3>
<p>
  <ul>
    <li>Case (111)</li>
    <ul>
      <li>All 3 packages are selected</li>
      <li>sumWeight = 10 + 20 + 30 = 60</li>
      <li>sumPayment = 60 + 100 + 120 = 280</li>
      <li>sumWeight (60) is greater than maxMass (50), so this combination is invalid.</li>
    </ul>
    <li>Case (110)</li>
    <ul>
      <li>Packages: Packages 1 and 2 are selected.</li>
      <li>sumWeight = 10 + 20 = 30</li>
      <li>sumPayment = 60 + 100 = 160</li>
      <li>sumWeight (30) is less than or equal to maxMass (50)</li>
      <li>maxPayment is updated to 160</li>
    </ul>
    <li>Case (101)</li>
    <ul>
      <li>Packages: Packages 1 and 3 are selected.</li>
      <li>sumWeight = 10 + 30 = 40</li>
      <li>sumPayment = 60 + 120 = 180</li>
      <li>sumWeight (40) is less than or equal to maxMass (50)</li>
      <li>maxPayment is updated to 180</li>
    </ul>
    <li>Case (100)</li>
    <ul>
      <li>Packages: Package 1 is selected.</li>
      <li>sumWeight = 10</li>
      <li>sumPayment = 60</li>
      <li>maxPayment remains 180</li>
    </ul>
    <li>Case (011)</li>
    <ul>
      <li>Packages: Packages 2 and 3 are selected.</li>
      <li>sumWeight = 20 + 30 = 50</li>
      <li>sumPayment = 100 + 120 = 220</li>
      <li>sumWeight (50) is less than or equal to maxMass (50)</li>
      <li>maxPayment is updated to 220</li>
    </ul>
    <li>Case (010)</li>
    <ul>
      <li>Packages: Package 2 is selected.</li>
      <li>sumWeight = 20</li>
      <li>sumPayment = 100</li>
      <li>maxPayment remains 220</li>
    </ul>
    <li>Case (001)</li>
    <ul>
      <li>Packages: Package 3 is selected.</li>
      <li>sumWeight = 30</li>
      <li>sumPayment = 120</li>
      <li>maxPayment remains 220</li>
    </ul>
    <li>Case (000)</li>
    <ul>
      <li>Packages: No packages are selected</li>
      <li>sumWeight = 0</li>
      <li>sumPayment = 0</li>
      <li>maxPayment remains 220</li>
    </ul>
  </ul>
</p>
