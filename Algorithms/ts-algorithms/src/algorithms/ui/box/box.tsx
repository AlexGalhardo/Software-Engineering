import { HTMLAttributes, ReactNode } from 'react'
import styles from './styles.module.css'
import clsx from 'clsx'

interface BoxProps extends HTMLAttributes<HTMLDivElement> {
  children?: ReactNode
  isCurrent?: boolean
  isActive?: boolean
  isDisabled?: boolean
  size?: 'sm' | 'md'
}

export function Box({ children, isCurrent, isActive, isDisabled, size = 'md' }: BoxProps) {
  const boxClassNames = clsx(
    styles.container,
    {
      [styles.active]: isActive,
      [styles.current]: isCurrent,
      [styles.disabled]: isDisabled,
      [styles.small]: size === 'sm'
    }
  )

  return (
    <div className={boxClassNames}>
      {children}
    </div>
  )
}
