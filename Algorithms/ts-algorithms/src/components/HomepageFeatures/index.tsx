import clsx from 'clsx';
import Heading from '@theme/Heading';
import styles from './styles.module.css';
import Translate from '@docusaurus/Translate';

type FeatureItem = {
  title: JSX.Element;
  Svg: React.ComponentType<React.ComponentProps<'svg'>>;
  description: JSX.Element;
};

const FeatureList: FeatureItem[] = [
  {
    title: (
      <Translate id="homepage.algorithmExploration.title">
        Algorithm Exploration
      </Translate>
    ),
    Svg: require('@site/static/img/undraw_programmer_re_owql.svg').default,
    description: (
      <Translate id="homepage.algorithmExploration.description">
        Dive into practical examples, exercises, and theory to understand algorithms.
        Perfect for acing technical interviews.
      </Translate>
    ),
  },
  {
    title: (
      <Translate id="homepage.practicalExamples.title">
        Practical Examples
      </Translate>
    ),
    Svg: require('@site/static/img/undraw_solution_mindset_re_57bf.svg').default,
    description: (
      <Translate id="homepage.practicalExamples.description">
        Explore real-world examples, allowing you to focus on understanding
        the core concepts without worrying about setup or boilerplate code.
      </Translate>
    ),
  },
  {
    title: (
      <Translate id="homepage.typescriptIntegration.title">
        TypeScript Integration
      </Translate>
    ),
    Svg: require('@site/static/img/undraw_developer_activity_re_39tg.svg').default,
    description: (
      <Translate id="homepage.typescriptIntegration.description">
        Seamlessly integrate TypeScript into your algorithm studies. Extend or
        customize your learning experience with the flexibility of TypeScript.
      </Translate>
    ),
  },
];

function Feature({title, Svg, description}: FeatureItem) {
  return (
    <div className={clsx('col col--4')}>
      <div className="text--center">
        <Svg className={styles.featureSvg} role="img" />
      </div>
      <div className="text--center padding-horiz--md">
        <Heading as="h3">{title}</Heading>
        <p>{description}</p>
      </div>
    </div>
  );
}

export default function HomepageFeatures(): JSX.Element {
  return (
    <section className={styles.features}>
      <div className="container">
        <div className="row">
          {FeatureList.map((props, idx) => (
            <Feature key={idx} {...props} />
          ))}
        </div>
      </div>
    </section>
  );
}
