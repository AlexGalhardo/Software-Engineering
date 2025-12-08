import { ReactNode } from 'react'
import styles from './styles.module.css'

interface DebuggerProps {
  children?: ReactNode
}

export function Debugger({ children }: DebuggerProps) {
  return (
    <pre className={styles.container}>
      {children}
    </pre>
  )
}
