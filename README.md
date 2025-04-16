# 🎈 Balloon Burst Game – Risk vs Reward Simulator

> ⚠️ **Note:**  
> This is a **base-level algorithmic version** of the balloon burst game implemented in Python/C.  
> The current design focuses on core mechanics — **multiplier growth, user-triggered cash-out, and burst logic**.  
> It is a **work in progress** and subject to balancing changes, gameplay tuning, and feature expansions.

---

## 📦 Version

**v0.1.0 – Base Mechanics Prototype**

---

## 🚀 How It Works

- 🎯 The multiplier starts at **1.0x** and increases by **0.04** per tick (reaching 2.0x in 25 steps).
- 💣 Every tick has a **5% chance** the balloon bursts.
- 💵 You place a bet each round and can press `ENTER` to **cash out** before it bursts.
- ✅ If you cash out in time, you earn:  
  `winnings = bet × multiplier`  
  Otherwise, you lose your bet.

---

## 🕹️ Gameplay Demo

```text
Enter starting balance: $100

Balance: $100.00
Enter bet: $10

Balloon inflating! Press ENTER anytime to cash out...
========================================
Current: 1.24x
Current: 1.28x
Current: 1.32x
<ENTER pressed>

Cashed out at 1.32x! +$3.20

Balance: $103.20
Play again? (y/n): y
