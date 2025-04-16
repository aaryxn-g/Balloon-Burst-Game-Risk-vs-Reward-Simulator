import random
import time
import threading

def balloon_game():
    balance = float(input("Enter starting balance: $"))
    
    while balance > 0:
        print(f"\nBalance: ${balance:.2f}")
        bet = float(input("Enter bet: $"))
        
        if bet > balance or bet <= 0:
            print("Invalid bet")
            continue

        multiplier = 1.0
        cashed_out = False
        stop_event = threading.Event()

        # Cash-out listener thread
        def cash_out_handler():
            nonlocal cashed_out
            input()
            cashed_out = True
            stop_event.set()
        
        thread = threading.Thread(target=cash_out_handler, daemon=True)
        thread.start()

        print("\nBalloon inflating! Press ENTER anytime to cash out...")
        print("========================================")

        BASE_DELAY = 0.45
        STEP_SIZE = 0.04  # Now 25 ticks to reach 2.0x

        try:
            while not stop_event.is_set():
                print(f"Current: {multiplier:.2f}x".ljust(20), end='\r')
                time.sleep(BASE_DELAY)
                multiplier += STEP_SIZE

                # Uniform 5% burst chance per tick
                if random.random() < 0.05:
                    break
        except KeyboardInterrupt:
            stop_event.set()
            break

        stop_event.set()

        if cashed_out:
            winnings = bet * multiplier
            balance += winnings - bet
            print(f"\nCashed out at {multiplier:.2f}x! +${winnings - bet:.2f}")
        else:
            balance -= bet
            print(f"\n💥 BURST at {multiplier:.2f}x! Lost ${bet:.2f}")

        if balance <= 0:
            print("\n💰 Game over - balance depleted!")
            break

        if input("\nPlay again? (y/n): ").lower() != 'y':
            break

    print(f"\nFinal balance: ${balance:.2f}")

if __name__ == "__main__":
    balloon_game()
