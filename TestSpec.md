**1. Test Case: InfersBreachAccordingToLimits**

**Purpose:**
To verify that the inferBreach function correctly classifies temperature values based on defined lower and upper limits.

**Inputs:**

**value:** The temperature value to test.
**lowerLimit:** The lower threshold for normal temperature.
**upperLimit:** The upper threshold for normal temperature.

**Expected Outputs:**

Returns NORMAL if the value is within the limits.
Returns TOO_HIGH if the value exceeds the upper limit.
Returns TOO_LOW if the value is below the lower limit.

**Test Cases:**

Input: value = 30, lowerLimit = 0, upperLimit = 35 → Expected Output: NORMAL
Input: value = 36, lowerLimit = 0, upperLimit = 35 → Expected Output: TOO_HIGH
Input: value = -1, lowerLimit = 0, upperLimit = 35 → Expected Output: TOO_LOW


**2. Test Case: ClassifiesTemperatureBreach**
**Purpose:**
To ensure that classifyTemperatureBreach function correctly identifies temperature breaches for different cooling types.

**Inputs:**

**coolingType:** The cooling type of the battery.
**temperatureInC:** The temperature in Celsius to check against the limits.

**Expected Outputs:**

Correct breach type based on the cooling type limits.

**Test Cases:**
**Input:** coolingType = PASSIVE_COOLING, temperatureInC = 30 → Expected Output: NORMAL
**Input:** coolingType = HI_ACTIVE_COOLING, temperatureInC = 46 → Expected Output: TOO_HIGH
**Input:** coolingType = MED_ACTIVE_COOLING, temperatureInC = -1 → Expected Output: TOO_LOW


**3. Test Case: SendsAlerts**
**Purpose:**
To verify that alerts are sent correctly based on the breach type and the alert target (Note: this test may require mocking for sendToController and sendToEmail).

**Inputs:**

**breachType:** The breach type to be sent.
**alertTarget:** The target to which the alert is sent (controller or email).

**Expected Outputs:**

Verifies that the correct alert function is called with the appropriate breach type.

**Test Cases (to be implemented with a mocking framework):**

**Input:** breachType = TOO_LOW, alertTarget = TO_CONTROLLER → Expected: Calls sendToController(TOO_LOW)
**Input:** breachType = TOO_HIGH, alertTarget = TO_EMAIL → Expected: Calls sendToEmail(TOO_HIGH)
